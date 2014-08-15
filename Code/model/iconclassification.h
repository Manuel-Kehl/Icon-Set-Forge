#ifndef ICONCLASSIFICATION_H
#define ICONCLASSIFICATION_H

#include <memory>
#include <QImage>
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
    /*!
     * Defines actions to be applied to Icons upon adding them to the
     * IconClassification. The most prominent example is probably the
     * resisizing to be performed when inserting Icons into a certain
     * "resolution" classification. Basically every kind of image processing
     * can be done.
     */
    class InsertCommand
    {
    public:
        /*!
         * To define a command just overwrite this function and perform all
         * necessary operations on the passed Icon pointer.
         * \param icon A reference to the Icon to operate on.
         */
        virtual void execute(QImage &icon) = 0;
    };

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
    /*!
     * The QVector to store the InsertCommands of this IconClassification in.
     * Because of InsertCommand's abstract nature one cannot create a
     * QVector<InsertCommand> as instead pointers are necessary.
     * Using std::unique_ptr would seem natural as IconClassification
     * is obviously the sole owner, but unfortunately Qt containers require
     * a copy constructor, which is why i have chosen std::shared_ptr.
     * TODO: Keep an eye on Qt's development and replace by std::unique_ptr,
     * as soon as Qt containers support C++11's move semantics properly.
     */
    QVector<std::shared_ptr<InsertCommand>> insertCommandChain;
    //! Defines if the icon set allows modification of this IconClassification
    bool immutable = false;
    //! indicates if the IconClassification is used for gropuing icons
    bool groupBy = false;
    //! indicates if icons of this IconClassification are to be displayed
    bool selected = false;
    //! indicates if the IconClassification is the root node of the tree
    bool isRoot = false;

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
    IconClassification(bool isRoot);
    bool hasParent() const;
    bool isRootNode() const;
    bool hasChildren() const;
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
     * name is already taken by a sibling of the IconClassification node, or
     * the classification is defined as 'immutable'
     */
    bool setName(QString name);
    /*!
     * Checks if one of the IconClassifications children has the given name.
     * \param childName The name to search for
     * \return true, if name is already taken, false if not
     */
    bool isNameTakenByChild(QString childName) const;
    /*!
     * Checks if two IconClassification instances are conflictingsiblings
     * within the tree (e.g. one and the same Icon can not be low
     * and high resolution at the same time, if the user really desired
     * to do so, he would have to create a linked icon to indicate that
     * intention). Due to the fact that the topmost IconClassifications (located
     * directly under the root node) do not conflict, siblings on that layer
     * would result in a false result.
     * \param other The other IconClassification to compare to.
     * \return If the compared IconClassifications conflict one another or not.
     */
    bool isConflicting(const IconClassification *other) const;
    const QString getName() const;
    //! To be called when the user has selected icons by this classification
    void setSelected(bool selected);
    //! Returns if this classification has been selected or not
    bool isSelected() const;
    //! To be called when the user has grouped icons by this classification
    void setGroupedBy(bool groupBy);
    //! Return if this classification has been set to group icons by or not
    bool isGroupedBy() const;
    //! Whether or not the classification is allowed to be modified
    bool isImmutable() const;
    /*!
     * Sets the immutable state of the IconClassification.
     * Beware: Once set immutable, it cannot be changed anymore.
     */
    void setImmutable();
    // InsertCommand related functions
    /*!
     * Adds a command to the insert command chain.
     * \param command The command to be added.
     * std::unique_ptr has been chosen to clarify that ownership is taken
     * by this class.
     */
    void addInsertCommand(std::unique_ptr<InsertCommand> command);
    //! Applies all commands in the insert command chain to the specified icon
    void performInsertCommandChain(QImage &icon) const;
};

#endif // ICONCLASSIFICATION_H
