#ifndef STARTVIEW_H
#define STARTVIEW_H

#include <QWidget>

namespace Ui {
class StartView;
}

class StartView : public QWidget
{
    Q_OBJECT
    
public:
    explicit StartView(QWidget *parent = 0);
    ~StartView();
    
private:
    Ui::StartView *ui;
};

#endif // STARTVIEW_H
