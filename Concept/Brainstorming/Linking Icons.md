# Linking Icons

At least in the field of Freedesktop/Linux icon sets it is common practice to create symlinks to certain icons if different actions/apps/... share the same visual representation.
This should be somehow applicable to the data model of *Icon Set Forge*.

Instead of having an own `QImage` instance `Icons` of *"link"* type just have a pointer to the original `Icon`.

Operating directly on the file system one has to be careful when applying certain operations on icons with links. *Icon Set Forge* aims to make work on icon sets more convenient and thus should include an intelligent procedure of handling such situations:


## Operations on the Original Icon
If modifications are made to the original Icon's image data the user shall be asked how to proceed:

- Keep link, thereby inherit changes
- Copy Icon, so it is based on original Icon

Moreover operations that do not affect the Icon's image data shall simply result in the linked Icon's link to be updated.


## Operations on Linked Icons

The user shall always be asked if he wants to create a copy before modifying a linked Icons image data or want to edit the original Icon too.


## Implementation

- The original `Icon` must act as [Observable](https://en.wikipedia.org/wiki/Observer_pattern), that notifies its all its links upon changes.
- Whenever an `Icon's` image data is accessed with *write* privileges it has to be assured, that a check for the above situations is run. This can be implemented by proper isolation of the image data with strictly defined access functions.

### Additions/Changes to the Icon Class

#### To Do Soon

- Add `link` attribute
- Write special constructor for *link type* `Icon` instances

#### To Do when Modifying Operations are Implemented
- define `editRename, editDelete, editMove, ...` functions
- declare ways of ensuring a check is done when write acces to an icon image data is claimed
- Properly implement Observer pattern, so linked icons actually get notified of changes
    - `QVector<Icon*> observingLinks`  attribute and `notify(Modification)` function

