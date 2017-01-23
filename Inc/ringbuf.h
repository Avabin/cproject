#include <stdint.h>
#ifndef __RINGBUF_H
#define __RINGBUF_H
#pragma pack(push, 1)
typedef struct ringbuf_t{
	  uint8_t * buffer;     		// data buffer
	  uint32_t capacity;  			// maximum number of items in the buffer
	  uint32_t count;						// actual number of elements in buffer
	  volatile uint8_t *start;	// start item index
	  volatile uint8_t *end;		// end item index

}ringbuf_t;
#pragma pack(pop)

static ringbuf_t rb;

ringbuf_t *ringbuf_get();

int ringbuf_init(ringbuf_t * rb);

int ringbuf_pushp(ringbuf_t *rb, uint8_t * data);

int ringbuf_pushstr(ringbuf_t *rb, uint8_t * str);

int ringbuf_push(ringbuf_t *rb, uint8_t data);

int ringbuf_pop(ringbuf_t *rb, uint8_t * data);

/*
typedef struct ringbuf_t {
  uint8_t buffer[64];
  uint32_t capacity;
  uint32_t count;
  volatile uint32_t start;
  volatile uint32_t end;
} ringbuf_t;

static ringbuf_t *rb;

int ringbuf_init(ringbuf_t * rb, uint8_t bufmem[]);

int ringbuf_pushp(ringbuf_t *rb, uint8_t * data);

int ringbuf_pushstr(ringbuf_t *rb, uint8_t * str);

int ringbuf_push(ringbuf_t *rb, uint8_t data);

int ringbuf_pop(ringbuf_t *rb, uint8_t * data);
*/
/*
typedef struct circBuf_t {
    uint8_t * const buffer;
    uint8_t head;
    uint8_t tail;
    const uint32_t maxLen;
}circBuf_t;

static circBuf_t cb;

int newCircBuf(void);
int circBufPush(circBuf_t *c, uint8_t data);
int circBufPop(circBuf_t *c, uint8_t *data);
*/
#endif /* __RINGBUF_H */
