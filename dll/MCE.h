#ifdef MCE_EXPORTS
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif

// void DLL Animacao(char);

void DLL plotsin(char);

// void DLL PlotCic(char);