#include "LayersHandler.h"
#include "Properties/PropertiesWindow.h"
#include "Viewport/Viewport.h"
#include "Viewport/DockSpace.h"
#include "LevelHierarchy/LevelHierarchy.h"

LayersHandler::LayersHandler()
{
	CreateLayer<DockSpace>();
	CreateLayer<Viewport>();
	CreateLayer<PropertiesWindow>();
	CreateLayer<LevelHierarchy>();
}