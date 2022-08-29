#ifndef GLOBAL_H
#define GLOBAL_H

#ifdef LIBRARY_EXPORT
#define DLL_EXPORT __declspec(dllexport)
#else 
#define DLL_EXPORT __declspec(dllimport)
#endif

#endif // GLOBAL_H
