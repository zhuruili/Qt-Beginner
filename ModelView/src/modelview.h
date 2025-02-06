#pragma once
#include <QMainWindow>
#include <QListView>
#include <QWidget>
#include <QAbstractListModel>
#include <QStyledItemDelegate>
#include <vector>

class CustomModel : public QAbstractListModel
{
    Q_OBJECT

public:
    CustomModel(QObject *parent = nullptr);

    // 必须实现的虚函数，从QAbstractListModel继承
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
    std::vector<QString> m_data;
};

class CustomDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    CustomDelegate(QObject *parent = nullptr);

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

class modelview : public QMainWindow
{
    Q_OBJECT

public:
    modelview(QWidget *parent = nullptr);
    ~modelview();

private:
    QListView *m_listView;
    CustomModel *m_model;
    CustomDelegate *m_delegate;
};