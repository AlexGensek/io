//metadoc EventManager copyright Steve Dekorte 2002
//metadoc EventManager license BSD revised
/*metadoc EventManager description
Selects on sockets and checks for timeouts.
*/

#ifndef IOEVENTMANAGER_DEFINED
#define IOEVENTMANAGER_DEFINED 1

#include "IoState.h"
#include "IoObject.h"
#include "IoSocket.h"
#include "IoEvent.h"
#include "Socket.h"
#include <event.h>

typedef IoObject IoEventManager;

typedef struct
{
	void *eventBase;
	IoMessage *handleEventMessage;
	List *activeEvents;
} IoEventManagerData;

IoEventManager *IoEventManager_rawClone(IoEventManager *self);
IoEventManager *IoEventManager_proto(void *state);

void IoEventManager_mark(IoEventManager *self);
void IoEventManager_free(IoEventManager *self);

IoObject *IoEventManager_addEvent(IoEventManager *self, IoObject *locals, IoMessage *m);
IoObject *IoEventManager_removeEvent(IoEventManager *self, IoObject *locals, IoMessage *m);
IoObject *IoEventManager_timeoutEvent(IoEventManager *self, IoObject *locals, IoMessage *m);

IoObject *IoEventManager_setListenTimeout(IoEventManager *self, IoObject *locals, IoMessage *m);
IoObject *IoEventManager_listen(IoEventManager *self, IoObject *locals, IoMessage *m);
IoObject *IoEventManager_listenUntilEvent(IoEventManager *self, IoObject *locals, IoMessage *m);

IoObject *IoEventManager_hasActiveEvents(IoEventManager *self, IoObject *locals, IoMessage *m);
IoObject *IoEventManager_activeEvents(IoEventManager *self, IoObject *locals, IoMessage *m);

#endif
