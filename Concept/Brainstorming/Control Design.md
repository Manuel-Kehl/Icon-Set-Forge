### ===This Document Does Not Reflect The Current State Of Development===
It is only here "for the record", so others can reproduce the thoughts that led to certain decisions.

# Control Design and Scanner Strategies

Goal of this document is to find out what functionality the `AbstractScannerStrategy` (or whatever name the class(es) will finally have) must provide to operate on icon sets of different kinds and what the most efficient/elegant way of implementation may look like. At the time being the main development focus has been on the `model` classes, which are now mature enough to proceed with the implementation of the `control` mechanisms.


## Possible Operations on Icon Sets in General

- **Loading** icon sets
- **Viewing** icons
- **Deleting** icons
- **Renaming** icons
- Applying classification **filters** to icons
- **Grouping** icons by classification
- **Copying** icons
- **Linking** icons
- **Inserting** new icons
    - **Generating** versions according to classifications (e.g. resolution)?
    - Special classification type that applies **image processing filters** to new icons upon insertion
    - Must be detected and defined upon loading the icon set
- **Renaming** classifications
- **Adding** new classifications
- **Deleting** classifications
    - Also delete all underlying icons?    
- **Linking** classifications?
- **Assigning** new classifications to icons
- **Removing** classifications from icons



## Functional Requirements of `control` Classes

The mechanics can be split up into two parts, of which the first deals with bidirectional access to the icon set in persistent form. After the icon set has been loaded into memory the second part is responsible for modifying the icon set's in memory data structure.

The first part depends on the type of icon set and is to be implemented in form of an `AbstractScannerStrategy`.

The second part should not have any dependencies on '*real icon set types*', but operate completely abstract and transparent. 
It is represented by the `IconSetOperator`.


### `AbstractScannerStrategy`

- **Load** icon set (e.g. load icon files in folder hierarchy from file system)
    - Should **not be limited to files system** (e.g. web protocol or database access)
    - most icon sets will probably operate on the file system, though
    - one abstract **base class for all file system** based icon sets
    - **Scanner must extract names that are unique, but match icons between classifications**
        - e.g. following filenames: `menu_32.png, menu_128` should lead to two `Icon` instances with `name="menu"` in the two categories `32x32 pixel` and `128x128 pixel`.
        - This is important for filter and group mechanisms!
- **Save** icon set (e.g. write temporary changes to file system)
    - **Create** classifications
    - **Remove** classifications
    - (**Rename** can be achieved by create and remove?)
    - **Remove** icons
    - **Move** icons
    - **Copy** icons
    - **Link** icons
- Define **constraints** that limit the possible interactions with the icon set
    - e.g. disallow renaming particular classifciations (or display an alert)
    - maybe add a **flag to `IconClassification`** that saves that info
        - **immutable:** necessary for the semantic structure and *I/O* of the icon set -> **cannot be altered**
    - either **hard coded** or **dynamically recognized** when loading
- Define **operations for specific classifications**when inserting new icons: `IconClassificationCommand`
- Define **default group and select settings** for differnt categories (can be easily achieved, by setting the correct attributes upon creating the classifications)


### `IconSetOperator`

All operations are to be implemented using [Qt's command pattern implementation](http://qt-project.org/doc/qt-5/qundo.html) for two reasons: First of all **Undo/Redo history** (which every good tool should provide) and moreover the ability to see what changes have been applied, so the **saving procedure can be optimized** (instead of writing the whole icon set to disk, go through command history and only apply actual changes).

- **Adding** icons
- **Deleting** icons
- **Renaming** icons
- **Copying** icons
- **Linking** icons
- **Adding** classifications
- **Deleting** classifications
- **Renaming** classifications
- **Linking** classifications


## Ownership Relations between `AbstractScannerStrategy` and `IconSet`

Until now I did not really make up my mind about how the two classes are related to one another, which shall be changed in a "well-wrought" and future proof manner in the course of the following paragraphs.

One possible case is the inital **creation** of `IconSet` instances. The obvious procedure that comes to one's mind is the following:

- **instantiate `AbstractScannerStrategy`** and set the right parameters 
- call some sort of **load** function that returns a properly initialized `IconSet` instance

There are several situations that would **require a reference** to an `IconSet's` original `AbstractScannerStrategy`:

- **Updating** an `IconSet` to reload any changes that may have been applied externally
- **Saving** changes made to the IconSet

One possible solution is the recent (temporary) implementation of adding a member of `AbstractScannerStrategy` to `IconSet`. The downside is the fact, that there would be application logic (parsing, loading, saving) embedded in a model class that is meant to hold nothing but pure data.

### The Solution
The newly established `IconSetOperator` could be used as a superordinate node, that owns one `IconSet` and the related `AbstractScannerStrategy` instance per icon set. It has access to the underlying data and is used to interoperate with the user interface. This is exactly what a `control` class should be responsible for: Managing communication between `model` and `view`.


See also [Model Design](Model Design.md) where I collected the changes that have to be made to the model to enable the ideas mentioned above.

