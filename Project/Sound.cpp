#include "Sound.h"

void arrowKeySound() {
	//Source: https://pixabay.com/vi/sound-effects/success-02-68338/
	PlaySound(TEXT("Arrow_Key_Sound.wav"), NULL, SND_ASYNC);
}

void enterKeySound() {
	//Source: https://pixabay.com/vi/sound-effects/success-68578/
	PlaySound(TEXT("Enter_Key_Sound.wav"), NULL, SND_ASYNC);
}

void winSound() {
	//Source: https://pixabay.com/vi/sound-effects/winsquare-6993/
	PlaySound(TEXT("Win_Sound.wav"), NULL, SND_ASYNC);
}

void gameOverSound() {
	//Source: https://pixabay.com/vi/sound-effects/game-over-38511/
	PlaySound(TEXT("Game_Over_Sound.wav"), NULL, SND_ASYNC);
}

void rightPairSound() {
	//Source: https://samplefocus.com/samples/sound-fx-mario-coin
	PlaySound(TEXT("Right_Pair_Sound.wav"), NULL, SND_ASYNC);
}

void wrongPairSound() {
	//Source: https://freesound.org/people/JapanYoshiTheGamer/sounds/361255/
	PlaySound(TEXT("Wrong_Pair_Sound.wav"), NULL, SND_ASYNC);
}	

void gameStartSound() {
	//Source: https://pixabay.com/vi/sound-effects/game-start-6104/
	PlaySound(TEXT("Game_Start_Sound.wav"), NULL, SND_ASYNC);
}