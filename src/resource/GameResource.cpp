#include "GameResource.h"
#include "oxygine-framework.h"

namespace GameResource {
	oxygine::Resources ui;

	void load() {
		ui.loadXML("xmls/ui.xml");
	}

	void free() {
		ui.free();
	}
}