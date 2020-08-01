#ifndef PLAY_AUDIO_H
#define PLAY_AUDIO_H
#include <QThread>

class play_audio : public QThread
{
public:
    play_audio();
    int i;
protected:
    void run();
};

#endif // PLAY_AUDIO_H
