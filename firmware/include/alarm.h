#ifndef ALARM_H
#define ALARM_H

void alarmInit();
void alarmSave();
void alarmCheck(struct tm &t);
void alarmSound();
void alarmStop();

#endif
