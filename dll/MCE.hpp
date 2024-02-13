#ifdef MCE_EXPORTS
#define DLL __declspec(dllexport)
#else
#define DLL __declspec(dllimport)
#endif

// void DLL Animacao(char);

void DLL PlotSin(float);

// void DLL PlotCic(char);