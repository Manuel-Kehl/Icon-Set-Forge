# Model Design

By now a major part of the underlying data model has already been implemented.
Thinking about the `AbstractScannerImplementation` a few details and additions came to my mind, that I want to keep track of in this document.

## Additions to the `Icon` class
- `Icon` needs a **name** attribute
- `Icon` needs a **link** pointer that points to another icon
    - needs to be **updated when renaming or moving** the original icon, so link stays intact
    - both variants **exclude one another**. If `image` exists `link` cannot be set and vice versa (proper setter functions)
    
## Additions to the `IconClassification` class
- `IconClassification` needs an **atomic** flag
- `IconClassification` needs a list of **`IconClassificationCommands`** that define **how to operate on new items** upon inserting them (or moving them) into a particular classification (e.g. resizing, when moving to low resolution classification)
