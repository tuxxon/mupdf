#include "mupdf/fitz.h"
#include "mupdf/ucdn.h"

#include <string.h>

// 필요한 경우, TOFU 관련 정의를 유지
#ifdef TOFU
#define TOFU_NOTO
#define TOFU_SIL
#endif

// 폰트를 사용하지 않기 위해 모든 폰트 관련 코드를 비활성화
typedef struct {
	const unsigned char *data;
	const unsigned int *size;
	char family[48];
	int script;
	int lang;
	int subfont;
	int attr;
} font_entry;

#define END_OF_DATA -2
#define ANY_SCRIPT -1
#define NO_SUBFONT 0
#define REGULAR 0

// 빈 폰트 목록을 사용해 폰트 데이터를 로드하지 않도록 설정
static font_entry inbuilt_fonts[] = {
	{ NULL, 0, "", END_OF_DATA, FZ_LANG_UNSET, NO_SUBFONT, REGULAR }
};

// 폰트 로드 관련 함수들을 최소화하여 NULL을 반환하도록 설정
const unsigned char *fz_lookup_base14_font(fz_context *ctx, const char *name, int *size) {
	*size = 0;
	return NULL; // 기본 폰트를 로드하지 않음
}

const unsigned char *fz_lookup_builtin_font(fz_context *ctx, const char *family, int is_bold, int is_italic, int *size) {
	*size = 0;
	return NULL; // 내장 폰트를 로드하지 않음
}

const unsigned char *fz_lookup_cjk_font(fz_context *ctx, int ordering, int *size, int *subfont) {
	*size = 0;
	*subfont = 0;
	return NULL; // CJK 폰트를 로드하지 않음
}

const unsigned char *fz_lookup_noto_font(fz_context *ctx, int script, int language, int *size, int *subfont) {
	*size = 0;
	*subfont = 0;
	return NULL; // Noto 폰트를 로드하지 않음
}

const unsigned char *fz_lookup_noto_math_font(fz_context *ctx, int *size) {
	*size = 0;
	return NULL; // Noto 수학 폰트를 로드하지 않음
}

const unsigned char *fz_lookup_noto_music_font(fz_context *ctx, int *size) {
	*size = 0;
	return NULL; // Noto 음악 폰트를 로드하지 않음
}

const unsigned char *fz_lookup_noto_symbol1_font(fz_context *ctx, int *size) {
	*size = 0;
	return NULL; // Noto 심볼 폰트를 로드하지 않음
}

const unsigned char *fz_lookup_noto_symbol2_font(fz_context *ctx, int *size) {
	*size = 0;
	return NULL; // Noto 심볼 폰트를 로드하지 않음
}

const unsigned char *fz_lookup_noto_emoji_font(fz_context *ctx, int *size) {
	*size = 0;
	return NULL; // Noto 이모지 폰트를 로드하지 않음
}

const unsigned char *fz_lookup_noto_boxes_font(fz_context *ctx, int *size) {
	*size = 0;
	return NULL; // Noto 박스 폰트를 로드하지 않음
}
