#ifndef _GUI_H_
#define _GUI_H_

#include <cstdlib>
#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "opencv2/highgui/highgui_c.h"
#include <functional>
#include <QtWidgets/QWidget>
#include <QtCore/QTimer>
#include <QtCore/QDebug>
#include <QtWidgets/QApplication>
#include <QtGui/QResizeEvent>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QSpinBox>
#include <iostream>
#include <random>
#include <vector>
#include <QtCore/QDateTime>
#include <QtCore/QProcess>
#include <QtGui/QImage>
#include "emotionclassifier.h"

class Gui : public QWidget
{
    Q_OBJECT

public:
    Gui();
    ~Gui();

public slots:
    void showImage(QImage &img);
    void showEmotion(int &emotion_index);
private slots:

private:
    void resizeEvent(QResizeEvent *re);
    QHBoxLayout *base_layout;
    QVBoxLayout *control_layout;
    QLabel *hint_label;
    QLabel *display_face;
    QLabel *display_emoji,*display_msg;
    QWidget *display_center;
    QWidget *hint;
    QProcess *sound;
};
#endif
