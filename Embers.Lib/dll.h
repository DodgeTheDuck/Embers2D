#pragma once

#ifdef APP_EXP
#define EMB_API __declspec(dllexport)
#else
#define EMB_API __declspec(dllimport)
#endif