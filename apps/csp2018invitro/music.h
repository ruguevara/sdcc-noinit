/**
    @file music.h
*/
/*----------------------------------------------------------------------------*/
#ifndef music_h_E
#define music_h_E

#include <stdint.h>

/**
 * 	Указатель на функцию проигрывания
 *	 одного музыкального фрейма 1/50 сек.
 * 	Если музыка не звучит, то music_im2h == NULL
 */
extern void ( *music_im2h ) ();

/**
* @brief Переключатель мелодий
*	Возвращает 1, если началось проигрывание новой мелодии,
*	иначе 0
*/
uint8_t checkMusic();

/**
* @brief Переключатель мелодий по клавишам '1','2' ....
* 	k - код нажатой клавиши
*/
void keyMusic ( uint16_t k );

/*----------------------------------------------------------------------------*/
#endif /* music_h_E */