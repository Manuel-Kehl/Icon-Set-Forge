# Grouping

## Data Model

To enable grouping the existing model has to be extended using the [Composite pattern](https://en.wikipedia.org/wiki/Composite_pattern).
Introducing a new base class `IconComponent` which both `Icon` (leaf) and `IconGroup` (composite) are derived from.


## The Algorithm
  
Besides that one has to implement the grouping algorithm itself.
The first restriction is the depth of the classification to group by. If the icons are on layer `n` then grouping can only be applied classifications of `layer < n -1`.

As `AbstractScannerStrategy` is supposed to create `Icon` instances, with names that match between same icons in different classifications one can find out which icons belong together by comparing their names.
A very first draft of a possible algorithm is as follows:

### Group by First Classification

- iterate over all `Icons`
- for each `Icon`:
    - iterate over all other icons (possible optimization, if not all icons are parsed)
        - if icon of classification with same parent classification is found that matches the icon's name and all other classifications it is to be added to the icon's group
        
### Group by Additional Classification

For grouping by additional classifications on has to simply apply the algorithm mentioned above to the subgroups that are already existant, but of course within those groups ignore the classifications that icons have already been grouped by.
        
## State of Development

Right now this functionality is **very** low on the priority list. The aforementioned procedure may include several careless mistakes, as it is nothing but the very first idea I came up with after 2 minutes of thinking :-)

The primary motivation for even thinking about that at this state of development lies within necessity of altering the class structure (composite pattern) to prepare the code for later addition of that functionality without major refactoring.