#ifndef WORDBOOK_H
#define WORDBOOK_H

#include <QMainWindow>

namespace Ui {
class WordBook;
}
class QLineEdit;
class DB;

class WordBook : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit WordBook(QWidget *parent = 0);
    ~WordBook();
    
private:
    Ui::WordBook *ui;
    QLineEdit * searchBox;
    DB *dbInterface;

    void setupToolBar();
private slots:
    void importDB();
    void exportDB();

    void showSearchResult();

};

#endif // WORDBOOK_H
