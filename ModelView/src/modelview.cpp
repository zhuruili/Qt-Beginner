#include "modelview.h"

#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

modelview::modelview(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(400, 150);

    m_listView = new QListView(this);
    m_model = new CustomModel(this);
    m_delegate = new CustomDelegate(this);

    m_listView->setModel(m_model);
    m_listView->setItemDelegate(m_delegate);

    // 创建一个中心部件
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    // 创建布局并将列表视图添加到布局中
    QVBoxLayout *vLayout = new QVBoxLayout(centralWidget);
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addStretch();
    hLayout->addWidget(m_listView);
    hLayout->addStretch();

    vLayout->addLayout(hLayout);
    centralWidget->setLayout(vLayout);
}

modelview::~modelview()
{
}

CustomModel::CustomModel(QObject *parent)
    : QAbstractListModel(parent)
{
    // 初始化一些数据
    m_data = {"Item 1", "Item 2", "Item 3"};
}

int CustomModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return static_cast<int>(m_data.size());
}

QVariant CustomModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= static_cast<int>(m_data.size()))
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
        return m_data.at(index.row());

    return QVariant();
}

bool CustomModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        m_data.at(index.row()) = value.toString();
        emit dataChanged(index, index, {role});
        return true;
    }
    return false;
}

Qt::ItemFlags CustomModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | QAbstractListModel::flags(index);
}

CustomDelegate::CustomDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{
}

QWidget *CustomDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    return new QLineEdit(parent);
}

void CustomDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QLineEdit *lineEdit = qobject_cast<QLineEdit *>(editor);
    if (lineEdit)
    {
        lineEdit->setText(index.model()->data(index, Qt::EditRole).toString());
    }
}

void CustomDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit *lineEdit = qobject_cast<QLineEdit *>(editor);
    if (lineEdit)
    {
        model->setData(index, lineEdit->text(), Qt::EditRole);
    }
}

void CustomDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}