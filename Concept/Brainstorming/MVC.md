# Model - View - Control

This brainstorming document deals with the question of how the Operations on IconSet instances should be communicated and maintained between the classes. I strive to clarify the *MVC* relationships between the classes as some of them have been rather blurry. Things to tidy up:

- The `scannerstrategies` do not really act like control classes, but rather like some sort of helper utilities -> move `scannerstrategies` out of `control` package
- `view` contains `control` code for testing purpose (`IconSetBrowser`)

The first task can be achieved easily by automatic refactoring and should not be of much effort.
To accomplish the second task, there will be need of several more classes, that are responsible for communicating `IconSet` operations between the different packages.

## The New Classes

### `IconSetOperator` - One Handler per `IconSet`

Each `IconSet` has an `IconSetOperator` that is responsible for *loading and owning* the `IconSet`, maintaining an instance to its corresponding `AbstractScannerStrategy`, maintaining and owning a [`QUndoStack`](http://qt-project.org/doc/qt-4.8/qundostack.html) to enable *undo/redo functionality* via *Qt's command pattern* implementation.


### `Coordinator` - The Central Manager

For the purpose of maintaining multiple simultaneously opened `IconSet` instances and routing actions to the correct `IconSetOperator` there must be one superordinate class, `Coordinator` that keeps a record of the currently active `IconSet` and routes operations to the corresponding `IconSetOperator` instance.

## Communication

As we are writing an application that already heavily depends on the Qt framework the first thing that comes to mind when talking about inter class communication is [*Qt's famous Signal/Slot mechanism*](http://qt-project.org/doc/qt-4.8/signalsandslots.html).
During the next paragraphs I will try to clarify where it makes sense to use it and where not.

First of all one has to keep in mind, that classes have to be derived from `QObject`. I decided not to base the model classes on `QObject`, when I made my mind up about memory management strategies, as that would imply a lot of overhead for "small" classes of possible huge number like `Icon` or `IconClassification`.

My suggestion for inter class communication is as follows:

### `view` -> `control`

`Coordinator` should offer *slots* that can be used by the view classes to pass user input to the control mechanisms.

Possible examples:

- Active `IconSet` changed (view: switched to other tab)
- Rename/Move/Delete/Insert... `Icon` Action has been invoked
- Rename/Move/Delete/Insert... `IconClassification` Action has been invoked

### Intra `control`

Depending on the slot that has been called, `Coordinator` invokes the corresponding Method of the active `IconSetOperator`.

### `control` -> `model`

The `IconSetOperator` is then responsible for creating the correct `QUndoCommand` subclass to put on the `QUndoStack` and by that means also execute the operation on the `IconSet` instance maintained by this `IconSetOperator`.

### `model` -> `view`

As I have been using Qt's *model/view* implementation by subclassing `QAbstractItemModel` and `QAbstractListModel` this part has already been prepared. Because these classes are responsible for giving the `view` classes access to the `model` I organized them in the `access` package and will hereafter refer to them as `access` classes. One has to simply emit the corresponding `dataChanged` signal in an, whenever changes to the model have been made to inform the view classes.

The signal can only be called from within the class itself. Therefore `IconSet` will inform all relevant `access` objects via an [*Observer Pattern*](https://en.wikipedia.org/wiki/Observer_pattern). implementation.