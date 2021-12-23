#include <iostream>

extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
#include <libswscale/swscale.h>
#include <libavdevice/avdevice.h>
}

void showDevice()
{
	AVFormatContext* pFormat = NULL;
	pFormat = avformat_alloc_context();
	AVDictionary* dict = NULL;
	av_dict_set(&dict, "list_devices", "true", 0);
	AVInputFormat* fmt = NULL;
	fmt = av_find_input_format("dshow");
	avformat_open_input(&pFormat, "video=dummy", fmt, &dict);
}

void showOption()
{
	AVFormatContext* pFormat = avformat_alloc_context();
	AVDictionary* dict = NULL;
	av_dict_set(&dict, "list_options", "true", 0);
	AVInputFormat* fmt = av_find_input_format("dshow");
	avformat_open_input(&pFormat, "video=Integrated Camera", fmt, &dict);

}


int enumAllDevice()
{
	av_register_all();
	avdevice_register_all();

	std::cout << "device list:" << std::endl;
	showDevice();

	//std::cout << "device option:" << std::endl;
	//showOption();

	return 0;
}