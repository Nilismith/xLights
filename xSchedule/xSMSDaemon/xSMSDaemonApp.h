/***************************************************************
 * Name:      xSMSDaemonApp.h
 * Purpose:   Defines Application Class
 * Author:    xLights ()
 * Created:   2016-12-30
 * Copyright: xLights (http://xlights.org)
 * License:
 **************************************************************/

#ifndef xSMSDaemonAPP_H
#define xSMSDaemonAPP_H

#include <wx/app.h>

typedef bool (*p_xSchedule_Action)(const char* command, const wchar_t* parameters, const char* data, char* buffer, size_t bufferSize);


#endif // xSMSDaemonAPP_H
