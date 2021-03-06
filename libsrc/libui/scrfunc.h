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
	ctInsert=1,	// Вставка
	ctReplace=2	// Замена
} curTypes;

/**
 * @brief Типы рамки
 */
typedef enum borderTypes{
	btNone=0,	// нет
	btSingl=1,	// одинарная
	btDoubl=2	// двойная
} borderTypes;

/**
 * @brief 6 символов рамки:
 * 	- горизонатльная линия
 * 	- вертикальная линия
 * 	- левый верхний угол
 * 	- правый верхний угол
 * 	- левый нижний угол
 * 	- правый нижний угол
 */
typedef uint8_t*	box_symbols;

/**
 * @brief Цвет
 */
typedef uint16_t	tColor;


/**
* @brief Точка
*/
typedef struct wPoint{
	uint8_t	x;
	uint8_t	y;
}wPoint;

/**
* @brief Размеры
*/
typedef struct wSize{
	uint8_t	w;
	uint8_t	h;
}wSize;

/**
* @brief Окно
*/
typedef struct wRect{
	wPoint	point;
	wSize	size;
}wRect;

/**
 * @brief Типы экранов
 */
typedef enum modeScreen{
	modeZX=0,	// Стандартный ZX
	modeText=1,	// Текстовый
	
} modeScreen;

/**
 * @brief Описатель куска сохраненного экрана
 * 	По сути - спрайт для графики
 * 
 * ---	поля не менять! вызовы из ассемблера	---
 */
typedef struct {
	// Режим экрана
	uint8_t  mode;
	// Координаты и размеры
	uint8_t  x;
	uint8_t  y;
	uint8_t  w;
	uint8_t  h;
	// Данные спрайта. Графика и, если надо, доп. данные
	uint8_t	 datap[];	// размер get_win_size(w, h);
} scrDriverStored;

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
	tColor		paper;
	
	/**
	 * @brief Текущий цвет экрана (тон)
	 */
	tColor		ink;
	
	/**
	 * @brief Позиция курсора
	 */
	uint8_t		cur_x;
	uint8_t		cur_y;
	tColor		cur_color;
	
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
	void	(*store_window)(scrDriverStored* buf, uint8_t x, uint8_t y, uint8_t w, uint8_t h);
	
	/**
	 * @brief Вывести окно из буфера на экран
	 */
	void	(*restore_window)(scrDriverStored* buf);
	
	/**
	 * @brief Вывести символ в позицию курсора цветом ink
	 */
	void	(*putc)(char c);
	
	/**
	 * @brief Вывести строку в позицию курсора
	 * 	Выводится не более maxsize символов
	 * 	maxsize = 0 - вывод до конца строки или экрана
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
	void	(*border)(uint8_t btype, uint8_t x, uint8_t y, uint8_t w, uint8_t h);
	
} scrDriverFunc;

/**
 * @brief Драйвер экрана
 */

// Текущий драйвер
extern scrDriverFunc*	txt_screen_driver;

/**
 * @brief Адрес текущего шрифта
 */
extern uint8_t*		current_font;

/**
 * @brief рамка одинарная
 */
extern box_symbols	boxSingle;

/**
 * @brief рамка двойная
 */
extern box_symbols	boxDouble;

/**
 * @brief Стандартная процедура рисования рамки
 * 
 */
void borderUI(uint8_t btype, uint8_t x, uint8_t y, uint8_t w, uint8_t h);

/**
 * @brief Установить драйвер экрана ZX
 */
void setScrDriverZX();

#endif /* scrfunc_h_E */
