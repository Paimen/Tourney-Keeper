#include "hintcombobox.h"
#include <QWheelEvent>

HintComboBox::HintComboBox(QWidget *parent) :
    QComboBox(parent)
{
}


void HintComboBox::showPopup()
{
    int index = findText(m_text);
    if(index == 0)
    {
      removeItem(0);
    }
    QComboBox::showPopup();


}

void HintComboBox::wheelEvent(QWheelEvent *e)
{
    e->accept();
}




void HintComboBox::setHintText(const QString &a_text)
{
    m_text = a_text;
}

