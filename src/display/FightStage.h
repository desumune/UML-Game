#include "oxygine-framework.h"
#include "AircraftFighter.h"
#include <list>
#include "Unit.h"

using namespace oxygine;

DECLARE_SMART(FightStage, spFightStage);

class FightStage : public Actor {
protected:
	friend class AircraftFighter; 
	friend class Rocket;
	friend class Unit;
	friend class Pickup;

	spAircraftFighter _af1;
	spAircraftFighter _af2;

	spTextField createText(const std::string& txt, const std::string& color);

	spSprite _bg;
	spSprite _guiPLayerRed;
	spSprite _guiPLayerGreen;
	spSprite _bgClouds;
	spTween _fightStageTween;
	spTextField playerRedHealthLevel;
	spTextField playerGreenHealthLevel;
	std::list<spUnit> _units;

	void doUpdate(const UpdateState& us);
	void _initGui();
	void _initBgClouds();

public:
	FightStage();
	~FightStage();

	void init();
};