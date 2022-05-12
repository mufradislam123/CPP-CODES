#ifndef VIDEO_H
#define VIDEO_H
#include "Media.h"

class Video :public Media {
private:
	string resolution;
	string format;
	string quality;

public:
	Video(string identifier = "", string username = "", int time = 0, string res = "", string fmt = "", string qty = "") : Media(identifier, username, time), resolution{ res }, format{ fmt }, quality{ qty }  {

	}
	virtual void ReadData(istream& is) {
		Media::ReadData(is);
		if (!is.eof()) {
			getline(is>>ws, resolution);
			getline(is, format);
			getline(is, quality);
		}
	}
	virtual void WriteData(ostream& os) {
		Media::WriteData(os);
		os << resolution << endl;
		os << format << endl;
		os << quality << endl;
	}
	virtual string getType() const {
		return "Video";
	}
};
#endif
