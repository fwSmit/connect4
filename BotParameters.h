#ifndef BOTPARAMS_H
#define BOTPARAMS_H

struct BotParameters{
	int TwoInARow;
	int ThreeInARow;
	BotParameters(int _TwoInARow, int _ThreeInARow): TwoInARow(_TwoInARow), ThreeInARow(_ThreeInARow){}
};

#endif
