#include "LSCommand.h"
#include <string>
#include "MetadataDisplayVisitor.h"

LSCommand::LSCommand(AbstractFileSystem* in_sys, AbstractFileFactory* in_fact) {
	factory = in_fact;
	system = in_sys;
}

int LSCommand::execute(string option) {
	if (option == " ") {
		system->getFileNames();
	}
	else if (option == "-m") {
		AbstractFileVisitor* metaVisitor = new MetadataDisplayVisitor;
		for (auto file = system->files().begin(); file != files.end(); ++file) {
		metaVisitor->visit();
	}
}