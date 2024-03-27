#include "Sound.h"

void arrowKeySound() {
	//reference: https://pixabay.com/vi/sound-effects/success-02-68338/
	PlaySound(TEXT("Arrow_Key_Sound.wav"), NULL, SND_ASYNC);
}

void enterKeySound() {
	//reference: https://pixabay.com/vi/sound-effects/success-68578/
	PlaySound(TEXT("Enter_Key_Sound.wav"), NULL, SND_ASYNC);
}

void winSound() {
	//reference: https://pixabay.com/vi/sound-effects/winsquare-6993/
	PlaySound(TEXT("Win_Sound.wav"), NULL, SND_ASYNC);
}

void gameOverSound() {
	//reference: https://pixabay.com/vi/sound-effects/game-over-38511/
	PlaySound(TEXT("Game_Over_Sound.wav"), NULL, SND_ASYNC);
}

void rightPairSound() {
	//reference: https://samplefocus.com/samples/sound-fx-mario-coin
	PlaySound(TEXT("Right_Pair_Sound.wav"), NULL, SND_ASYNC);
}

void wrongPairSound() {
	//reference: https://freesound.org/people/JapanYoshiTheGamer/sounds/361255/
	PlaySound(TEXT("Wrong_Pair_Sound.wav"), NULL, SND_ASYNC);
}	