/**
    @file scrfunc.h
    Функции для вывода на экран.
    Функции содержат примитивы оконного интерфейса.
*/
#ifndef scrfunc_h_E
#define scrfunc_h_E
#include <stdint.h>

/**
 * @brief Типы курсора
 */
typedef enum curTypes{
	ctNone=0,	// Невидимый (скрыть курсор)
	ctInsert,	// Вставка
	ctReplace	// Замена
} curTypes;

/**
 * @brief Типы рамки
 */
typedef enum borderTypes{
	btNone=0,	// нет
	btSingl,	// одинарная
	btDoubl		// двойная
} borderTypes;

typedef uint16_t	tColor;

/**
 * @brief Функции вывода на экран
 * 	Все функции привязаны к знакоместам 8x8 пикселей
 */
typedef struct {
	/**
	 * @brief размеры экрана
	 */
	uint8_t w;
	uint8_t h;
	
	/**
	 * @brief Текущий цвет экрана (фон)
	 */
	uint16_t	paper;
	
	/**
	 * @brief Текущий цвет экрана (тон)
	 */
	uint16_t	ink;
	
	/**
	 * @brief Позиция курсора
	 */
	uint8_t		cur_x;
	uint8_t		cur_y;
	
	/**
	 * @brief Тип курсора
	 */
	curTypes	cur_type;
	
	/**
	 * @brief Установка цвета
	 */
	void (*setcolor)(tColor ink, tColor paper);
	
	/**
	 * @brief Очистка окна текущими цветами
	 *	Координаты относительно
	 */
	void (*clear_window)(uint8_t x, uint8_t y, uint8_t w, uint8_t h);
	
	/**
	 * @brief Вычисление размера памяти, потребного для сохранения окна,
	 * 	заданного размера
	 */
	uint32_t (*get_win_size)(uint8_t w, uint8_t h);
	
	/**
	 * @brief Сохранить окно заданного размера в буфере
	 */
	void	(*store_window)(void* buf, uint8_t x, uint8_t y, uint8_t w, uint8_t h);
	
	/**
	 * @brief Вывести окно из буфера на экран
	 */
	void	(*restore_window)(void* buf, uint8_t x, uint8_t y, uint8_t w, uint8_t h);
	
	/**
	 * @brief Вывести символ в позицию курсора цветом ink
	 */
	void	(*putc)(char c);
	
	/**
	 * @brief Вывести строку в позицию курсора
	 * 	Выводится не более maxsize символов,
	 * 	остальное добивается пробелами,
	 * 	если строка короче maxsize
	 */
	void	(*puts)(const char* s, uint8_t maxsize);
	
	/**
	 * @brief Установить позицию позицию курсора
	 */
	void	(*curpos)(uint8_t x, uint8_t y);
	
	/**
	 * @brief Установить тип курсора
	 */
	void	(*curset)(tColor color, curTypes t);
	
	/**
	 * @brief Вывести рамку заданного типа
	 */
	void	(*border)(borderTypes btype, uint8_t x, uint8_t y, uint8_t w, uint8_t h);
	
} scrDriverFunc;

/**
 * @brief Драйвер экрана
 */
extern scrDriverFunc*	txt_screen_driver;

#endif /* scrfunc_h_E */