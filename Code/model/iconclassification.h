#ifndef ICONCLASSIFICATION_H
#define ICONCLASSIFICATION_H

#include <memory>
#include <QVector>
#include <QString>

/*!
 * Defines a way of classifying icons.
 * Possible "real life examples" include resolution, category or target device.
 * It is used to filter and group icons by certain criteria. Organizing
 * IconClassifications in a tree structure is possible by adding children.
 */
class IconClassification
{
private:
    QString name;
    /*!
     * A pointer to the parent node. It is important, that this pointer is
     * of weak nature (which raw pointers are) to avoid cyclic references within
     * the tree structure that would lead to memory leakage.
     * There must be no way of modifying this pointer from outside this class,
     * to avoid illegit changes to the tree structure. It gets set automatically
     * when an IconClassification is assigned as a child to another instance.
     */
    IconClassification *parent;
    //! Children are being added to this vector
    QVector<std::shared_ptr<IconClassification>> children;
    //! indicates if the IconClassification is used for gropuing icons
    bool groupBy = false;
    //! indicates if icons of this IconClassification are to be displayed
    bool selected = false;

    /*!
     * Sets the parent of this IconClassification node.
     * It has been marked private to prevent acces from outside.
     * \param parent The parent to be set
     * \sa IconClassification::parent
     */
    void setParent(IconClassification *parent);

public:
    /*!
     * Constructor of the IconClassification class.
     * Always set a name after instantiating an IconClassification.
     * The only reason to separate these functions is the fact that
     * setting the name must be done with a return value, that indicates
     * success of the operation.
     * \sa IconClassification::setName(QString)
     */
    IconClassification();
    bool hasParent();
    bool hasChildren();
    /*!
     * Enables acces to the parent of this IconClassification node.
     * \return A pointer to the node's parent.
     * Do <b>under no circumstances</b> delete the pointer returned by
     * this function.
     */
    IconClassification *getParent();
    /*!
     * Enables access to the children of this IconClassification node.
     * \return A QVector of std::shared_ptrs, that point towards this
     * IconClassification's children.
     */
    QVector<std::shared_ptr<IconClassification>> getChildren();
    /*!
     * Returns the index of the child that has been passed.
     * \param child A pointer to the child index.
     * \return The index of the child within the list of children.
     */
    int getChildIndexOf(const IconClassification *child) const;
    /*!
     * Adds a child to this particular IconClassification node.
     * \param child the child IconClassification to be added.
     * A std::unique_ptr is passed to indicate that ownership of the child
     * is being taken by this function.
     * \return If the child has been added successfully. Adding a child may be
     * refused in case a child of the same name already exists.
     */
    bool addChild(std::unique_ptr<IconClassification> child);
    /*!
     * A function for changing an IconClassification's name.
     * It is important, that IconClassifications have valid names, so always
     * check the return statement of this function and handle potential
     * problems
     * \param name The new name to be assigned to this IconClassification
     * \return Success state of the name change. false indicates, that the
     * name is already taken by a sibling of the IconClassification node, which
     * is not allowed.
     */
    bool setName(QString name);
    /*!
     * Checks if one of the IconClassifications children has the given name.
     * \param childName The name to search for
     * \return true, if name is already taken, false if not
     */
    bool isNameTakenByChild(QString childName);
    const QString getName() const;
    //! To be called when the user has selected icons by this classification
    void setSelected(bool selected);
    //! Returns if this classification has been selected or not
    bool isSelected();
    //! To be called when the user has grouped icons by this classification
    void setGroupedBy(bool groupBy);
    //! Return if this classification has been set to group icons by or not
    bool isGroupedBy();
};

#endif // ICONCLASSIFICATION_H
