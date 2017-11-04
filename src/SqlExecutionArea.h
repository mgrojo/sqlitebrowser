#ifndef SQLEXECUTIONAREA_H
#define SQLEXECUTIONAREA_H

#include <QWidget>

class SqlTextEdit;
class SqliteTableModel;
class DBBrowserDB;
class ExtendedTableWidget;

namespace Ui {
class SqlExecutionArea;
}

class SqlExecutionArea : public QWidget
{
    Q_OBJECT

public:
    explicit SqlExecutionArea(DBBrowserDB& _db, QWidget* parent = nullptr);
    ~SqlExecutionArea();

    QString getSql() const;
    QString getSelectedSql() const;

    QString fileName() const { return sqlFileName; }
    void setFileName(const QString& filename) { sqlFileName = filename; }

    SqliteTableModel* getModel() { return model; }
    SqlTextEdit* getEditor();
    ExtendedTableWidget *getTableResult();
    
public slots:
    virtual void finishExecution(const QString& result);
    virtual void saveAsCsv();
    virtual void saveAsView();
    virtual void reloadSettings();
    void fetchedData();

private:
    DBBrowserDB& db;
    SqliteTableModel* model;
    QString sqlFileName;
    Ui::SqlExecutionArea* ui;
    bool m_columnsResized;              // This is set to true if the columns of the table view were already adjusted to fit their contents
};

#endif
