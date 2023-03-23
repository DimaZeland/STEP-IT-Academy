#pragma once
typedef unsigned short ushort;

class Remote;

class Tv {
private:
    bool OnOff = false;
    ushort vol = 0;
    ushort channel = 1;
    const ushort size_channel = 50;
    const ushort max_vol = 100;
public:
    Tv(bool ONOFF = 0, ushort VOL = 0, ushort CHANNEL = 1, ushort SIZE_CHANNEL = 50, ushort MAX_VOL = 100)
            : OnOff(ONOFF), vol(VOL), channel(CHANNEL), size_channel(SIZE_CHANNEL), max_vol(MAX_VOL) {}

    inline void Power() { OnOff = !OnOff; }

    inline void nextChannel() { if (OnOff) channel < size_channel ? ++channel : channel; }

    inline void prevChannel() { if (OnOff) channel > 1 ? --channel : channel; }

    inline void incVolume() { if (OnOff) vol < max_vol ? ++vol : vol; }

    inline void decVolume() { if (OnOff) vol > 0 ? --vol : vol; }

    friend class Remote;
};

class Remote {
public:
    inline void power(Tv &q) { q.OnOff = !q.OnOff; }

    inline void nextChannel(Tv &q) { if (q.OnOff) q.channel < q.size_channel ? ++q.channel : q.channel; }

    inline void prevChannel(Tv &q) { if (q.OnOff) q.channel > 1 ? --q.channel : q.channel; }

    inline void incVolume(Tv &q) { if (q.OnOff) q.vol < q.max_vol ? ++q.vol : q.vol; }

    inline void decVolume(Tv &q) { if (q.OnOff) q.vol > 0 ? --q.vol : q.vol; }

    inline void goToChannel(Tv &q, ushort ch) { if (q.OnOff and ch) q.channel = ch < q.size_channel ? ch : q.channel; }
};
