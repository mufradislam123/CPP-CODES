#ifndef AUDIO_H
#define AUDIO_H
#include "Media.h"

class Audio :public Media {
private:
	string format;
	string quality;

public:
	Audio(string identifier = "", string username = "", int time = 0, string fmt = "", string qty = "") : Media(identifier, username, time), format{ fmt }, quality{ qty }  {
		
	}
	virtual void ReadData(istream& is) {
		Media::ReadData(is);
		if (!is.eof()) {
			getline(is>>ws, format);
			getline(is, quality);
		}
	}
	virtual void WriteData(ostream& os) {
		Media::WriteData(os);
		os << format << endl;
		os << quality << endl;
	}
	virtual string getType() const {
		return "Audio";
	}
};
#endif
