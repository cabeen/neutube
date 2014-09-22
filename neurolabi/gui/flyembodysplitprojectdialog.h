#ifndef FLYEMBODYSPLITPROJECTDIALOG_H
#define FLYEMBODYSPLITPROJECTDIALOG_H

#include <QDialog>
#include <QGraphicsScene>
#include "flyem/zflyembodysplitproject.h"
#include "dvid/zdvidtarget.h"

class MainWindow;
class ZFlyEmNewBodySplitProjectDialog;
class QProgressDialog;

namespace Ui {
class FlyEmBodySplitProjectDialog;
}

class FlyEmBodySplitProjectDialog : public QDialog
{
  Q_OBJECT

public:
  explicit FlyEmBodySplitProjectDialog(QWidget *parent = 0);
  ~FlyEmBodySplitProjectDialog();

  void setDvidTarget(const ZDvidTarget &target);
  void setBodyId(int id);

  int getBodyId() const;
  const ZDvidTarget& getDvidTarget() const;

  MainWindow* getMainWindow();
  QProgressDialog* getProgressDialog();

  void setDataFrame(ZStackFrame *frame);

  void closeEvent(QCloseEvent *event);
  void setLoadBodyDialog(ZFlyEmNewBodySplitProjectDialog *dlg);

  void updateButton();
  void updateWidget();
  void updateBookmarkTable();

  bool isBodyLoaded() const;

signals:
  //void progressStarted();
  void progressDone();
  void messageDumped(const QString &message, bool appending);

public slots:
  void clear();
  void shallowClear();
  void shallowClearResultWindow();
  void shallowClearDataFrame();

  void showData2d();
  void showData3d();
  void showResult3d();
  void loadBody();
  void loadBookmark();
  void locateBookmark(const QModelIndex &index);
  void quickView();

  /*!
   * \brief Dump information
   */
  void dump(const QString &info, bool appending = false);


private slots:
  void on_pushButton_clicked();

private:
  void updateSideView();
  void updateSideViewFunc();
  void startProgress(const QString &label);

private:
  Ui::FlyEmBodySplitProjectDialog *ui;
  ZFlyEmNewBodySplitProjectDialog *m_loadBodyDlg;
  ZFlyEmBodySplitProject m_project;
  ZFlyEmBookmarkListModel m_bookmarkList;
  QGraphicsScene *m_sideViewScene;
};

#endif // FLYEMBODYSPLITPROJECTDIALOG_H
