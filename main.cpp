#include <QApplication>
#include <QPushButton>
#include <QTreeView>
#include <QFileSystemModel>
#include <QSplitter>
#include <QListView>
#include <QTextEdit>
#include <QHBoxLayout>
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QWidget* window=new QWidget;
    QHBoxLayout* layout = new QHBoxLayout;
    // QPushButton button("Hello world!", nullptr);
    // button.resize(200, 100);
    // button.show();

    QSplitter *splitter = new QSplitter(window);
    // splitter->acceptDrops();
    QListView *listview = new QListView;
    QTreeView *treeview = new QTreeView;
    QTextEdit *textedit = new QTextEdit;
    splitter->addWidget(listview);
    splitter->addWidget(treeview);
    splitter->addWidget(textedit);
    QTreeView *tree = new QTreeView(splitter);

    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());
    tree->setModel(model);
    layout->addWidget(tree);
    window->setLayout(layout);
    window->show();

    return app.exec();
}
