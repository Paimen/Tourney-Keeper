#ifndef HINTCOMBOBOX_H
#define HINTCOMBOBOX_H

#include <QComboBox>

class HintComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit HintComboBox(QWidget *parent = 0);
    void setHintText(const QString &a_text);
    
signals:

protected:
    void showPopup();
    void wheelEvent(QWheelEvent * e);

    
public slots:

private:
    QString m_text;
    
};

#endif // HINTCOMBOBOX_H
