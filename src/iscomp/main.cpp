#include <iostream>
#include <FLAC++/encoder.h>
#include <memory>
#include <wienerFilter.h>

class MEncoder: public FLAC::Encoder::File {
public:

	MEncoder() { }

protected:
	virtual void progress_callback(FLAC__uint64 bytes_written, FLAC__uint64 samples_written, uint32_t frames_written, uint32_t total_frames_estimate)
    {
        std::cout << "bytewritten" << std::endl;
    }
};


int main()
{
    MEncoder me;

    me.set_channels(1);
    me.set_blocksize(0);
    me.set_bits_per_sample(16);
    me.set_sample_rate(44000);
    me.set_total_samples_estimate(std::pow(2, 18));

    size_t const bsize = 4096;
    FLAC__int16 buffer[bsize];
    FILE* mfile = fopen("./0002.isw", "rb");
    int nread = 0;
    while (true){
        nread = fread(buffer, sizeof(FLAC__int16), bsize, mfile);
        //me.process_interleaved(buffer, nread);
    }

    me.init("./test.isc");
    
    return 0;
}