#ifndef FADEIN_ANIMATION_H
#define FADEIN_ANIMATION_H

template<class T>
void set_fade_in(T obj){
    QGraphicsOpacityEffect *  pEffect;
    QPropertyAnimation * pAnimation;

    pEffect = new QGraphicsOpacityEffect(obj);
    pEffect->setOpacity(0);
    obj->setGraphicsEffect(pEffect);

    pAnimation = new QPropertyAnimation(pEffect,"opacity",obj);
    pAnimation->setDuration(1500);
    pAnimation->setStartValue(0);
    pAnimation->setEndValue(1.0);
    pAnimation->start();
}

#endif // FADEIN_ANIMATION_H
