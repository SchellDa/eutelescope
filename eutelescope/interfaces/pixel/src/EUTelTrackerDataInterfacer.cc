//#include "EUTelTrackerDataInterfacer.h"

using namespace eutelescope;

std::vector<std::reference_wrapper<EUTelBaseSparsePixel const>> const &
EUTelTrackerDataInterfacer::getPixels() const {
	if (!_refVecValid) {
		this->validateRefVec();
	}
	return _refVec;
}

auto EUTelTrackerDataInterfacer::begin() const {
      if (!_refVecValid)
        this->validateRefVec();
      return _refVec.cbegin();
    }

auto EUTelTrackerDataInterfacer::end() const {
      if (!_refVecValid)
        this->validateRefVec();
      return _refVec.cend();
    }

