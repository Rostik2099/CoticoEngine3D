#pragma once
#include<map>
#include<string>

enum ActionType
{
	IE_PRESS,
	IE_RELEASE,
};

static std::map<std::string, int> keyMapping;

class KeyMapping 
{
public:
	KeyMapping() 
	{
		keyMapping["UNKNOWN"] = -1;
		keyMapping["SPACE"] = 32;
		keyMapping["APOSTROPHE"] = 39; /* ' */
		keyMapping["COMMA"] = 44; /* , */
		keyMapping["MINUS"] = 45; /* - */
		keyMapping["PERIOD"] = 46; /* . */
		keyMapping["SLASH"] = 47; /* / */
		keyMapping["0"] = 48;
		keyMapping["1"] = 49;
		keyMapping["2"] = 50;
		keyMapping["3"] = 51;
		keyMapping["4"] = 52;
		keyMapping["5"] = 53;
		keyMapping["6"] = 54;
		keyMapping["7"] = 55;
		keyMapping["8"] = 56;
		keyMapping["9"] = 57;
		keyMapping["SEMICOLON"] = 59; /* ; */
		keyMapping["EQUAL"] = 61; /* = */
		keyMapping["A"] = 65;
		//keyMapping[B   66
		//keyMapping[
		//keyMapping[C   67
		keyMapping["D"] = 68;
		//keyMapping[E   69
		//keyMapping[
		//keyMapping[F   70
		//keyMapping[
		//keyMapping[G   71
		//keyMapping[
		//keyMapping[H   72
		//keyMapping[
		//keyMapping[I   73
		//keyMapping[
		//keyMapping[J   74
		//keyMapping[
		//keyMapping[K   75
		//keyMapping[
		//keyMapping[L   76
		//keyMapping[
		//keyMapping[M   77
		//keyMapping[
		//keyMapping[N   78
		//keyMapping[
		//keyMapping[O   79
		//keyMapping[
		//keyMapping[P   80
		//keyMapping[
		//keyMapping[Q   81
		//keyMapping[
		//keyMapping[R   82
		keyMapping["S"] = 83;
		//keyMapping[T   84
		//keyMapping[
		//keyMapping[U   85
		//keyMapping[
		//keyMapping[V   86
		keyMapping["W"] = 87;
		//keyMapping[X   88
		//keyMapping[
		//keyMapping[Y   89
		//keyMapping[
		//keyMapping[Z   90
		//keyMapping[
		//keyMapping[LEFT_BRACKET   91 /* [ */
		//keyMapping[
		//keyMapping[BACKSLASH   92 /* \ */
		//keyMapping[
		//keyMapping[RIGHT_BRACKET   93 /* ] */
		//keyMapping[
		//keyMapping[GRAVE_ACCENT   96 /* ` */
		//keyMapping[
		//keyMapping[WORLD_1   161 /* non-US #1 */
		//keyMapping[
		//keyMapping[WORLD_2   162 /* non-US #2 */
		//keyMapping[
		//keyMapping[ESCAPE   256
		//keyMapping[
		//keyMapping[ENTER   257
		//keyMapping[
		//keyMapping[TAB   258
		//keyMapping[
		//keyMapping[BACKSPACE   259
		//keyMapping[
		//keyMapping[INSERT   260
		//keyMapping[
		//keyMapping[DELETE   261
		//keyMapping[
		//keyMapping[RIGHT   262
		//keyMapping[
		//keyMapping[LEFT   263
		//keyMapping[
		//keyMapping[DOWN   264
		//keyMapping[
		//keyMapping[UP   265
		//keyMapping[
		//keyMapping[PAGE_UP   266
		//keyMapping[
		//keyMapping[PAGE_DOWN   267
		//keyMapping[
		//keyMapping[HOME   268
		//keyMapping[
		//keyMapping[END   269
		//keyMapping[
		//keyMapping[CAPS_LOCK   280
		//keyMapping[
		//keyMapping[SCROLL_LOCK   281
		//keyMapping[
		//keyMapping[NUM_LOCK   282
		//keyMapping[
		//keyMapping[PRINT_SCREEN   283
		//keyMapping[
		//keyMapping[PAUSE   284
		//keyMapping[
		//keyMapping[F1   290
		//keyMapping[
		//keyMapping[F2   291
		//keyMapping[
		//keyMapping[F3   292
		//keyMapping[
		//keyMapping[F4   293
		//keyMapping[
		//keyMapping[F5   294
		//keyMapping[
		//keyMapping[F6   295
		//keyMapping[
		//keyMapping[F7   296
		//keyMapping[
		//keyMapping[F8   297
		//keyMapping[
		//keyMapping[F9   298
		//keyMapping[
		//keyMapping[F10   299
		//keyMapping[
		//keyMapping[F11   300
		//keyMapping[
		//keyMapping[F12   301
		//keyMapping[
		//keyMapping[F13   302
		//keyMapping[
		//keyMapping[F14   303
		//keyMapping[
		//keyMapping[F15   304
		//keyMapping[
		//keyMapping[F16   305
		//keyMapping[
		//keyMapping[F17   306
		//keyMapping[
		//keyMapping[F18   307
		//keyMapping[
		//keyMapping[F19   308
		//keyMapping[
		//keyMapping[F20   309
		//keyMapping[
		//keyMapping[F21   310
		//keyMapping[
		//keyMapping[F22   311
		//keyMapping[
		//keyMapping[F23   312
		//keyMapping[
		//keyMapping[F24   313
		//keyMapping[
		//keyMapping[F25   314
		//keyMapping[
		//keyMapping[KP_0   320
		//keyMapping[
		//keyMapping[KP_1   321
		//keyMapping[
		//keyMapping[KP_2   322
		//keyMapping[
		//keyMapping[KP_3   323
		//keyMapping[
		//keyMapping[KP_4   324
		//keyMapping[
		//keyMapping[KP_5   325
		//keyMapping[
		//keyMapping[KP_6   326
		//keyMapping[
		//keyMapping[KP_7   327
		//keyMapping[
		//keyMapping[KP_8   328
		//keyMapping[
		//	keyMapping[KP_9   329
		//		keyMapping[KP_DECIMAL   330
		//		keyMapping[KP_DIVIDE   331
		//		keyMapping[KP_MULTIPLY   332
		//		keyMapping[KP_SUBTRACT   333
		//		keyMapping[KP_ADD   334
		//		keyMapping[KP_ENTER   335
		//		keyMapping[KP_EQUAL   336
		keyMapping["LEFT_SHIFT"] = 340;
		keyMapping["LEFT_CONTROL"] = 341;
		//		keyMapping[LEFT_ALT   342
		//		keyMapping[LEFT_SUPER   343
		//		keyMapping[RIGHT_SHIFT   344
		keyMapping["RIGHT_CONTROL"] = 345;
		keyMapping["RIGHT_ALT"] = 346;
		keyMapping["RIGHT_SUPER"] = 347;
		keyMapping["MENU"] = 348;
	};
};