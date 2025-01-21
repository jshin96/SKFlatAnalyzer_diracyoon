#all: DataFormats AnalyzerTools GEScaleSyst Analyzers AnalyzersHNL AnalyzersHNLExternal AnalyzersHNLOpt Archive
all: DataFormats AnalyzerTools Analyzers AnalyzersHNL AnalyzersHNLExternal AnalyzersHNLOpt Archive

DataFormats::
	(cd DataFormats; make)
	(mvexist.sh DataFormats/src/DataFormats_Dict_rdict.pcm lib/)
	(mvexist.sh DataFormats/libDataFormats.rootmap lib/)

AnalyzerTools::
	(cd AnalyzerTools; make)
	(mvexist.sh AnalyzerTools/src/AnalyzerTools_Dict_rdict.pcm lib/)
	(mvexist.sh AnalyzerTools/libAnalyzerTools.rootmap lib/)

#GEScaleSyst::
#	(cd external/GEScaleSyst; make)
#	(mvexist.sh external/GEScaleSyst/GEScaleSyst_Dict_rdict.pcm lib/)
#	(mvexist.sh external/GEScaleSyst/libGEScaleSyst.rootmap lib/)

Analyzers::
	(cd Analyzers; make)
	(mvexist.sh Analyzers/src/Analyzers_Dict_rdict.pcm lib/)
	(mvexist.sh Analyzers/libAnalyzers.rootmap lib/)

AnalyzersHNL::
	(cd Analyzers/HNL; make)
	(mvexist.sh Analyzers/HNL/src/HNLAnalyzers_Dict_rdict.pcm lib/)
	(mvexist.sh Analyzers/HNL/libHNLAnalyzers.rootmap lib/)

AnalyzersHNLExternal::
	(cd Analyzers/HNLExternal; make)
	(mvexist.sh Analyzers/HNLExternal/src/HNLExternalAnalyzers_Dict_rdict.pcm lib/)
	(mvexist.sh Analyzers/HNLExternal/libHNLExternalAnalyzers.rootmap lib/)

AnalyzersHNLOpt::
	(cd Analyzers/HNLOpt; make)
	(mvexist.sh Analyzers/HNLOpt/src/HNLOptAnalyzers_Dict_rdict.pcm lib/)
	(mvexist.sh Analyzers/HNLOpt/libHNLOptAnalyzers.rootmap lib/)


Archive::
	(tar -zcf lib/DataFormats.tar.gz DataFormats)
	(tar -zcf lib/AnalyzerTools.tar.gz AnalyzerTools)
#	(tar -zcf lib/GEScaleSyst.tar.gz external/GEScaleSyst/GEScaleSyst.*)
	(tar -zcf lib/Analyzers.tar.gz Analyzers)

clean::
	(cd DataFormats; make clean)
	(cd AnalyzerTools; make clean)
	(cd external/GEScaleSyst; make clean)
	(cd Analyzers; make clean)
	(cd Analyzers/HNL; make clean)
	(cd Analyzers/HNLExternal; make clean)
	(cd Analyzers/HNLOpt; make clean)

distclean::
	(cd DataFormats; make distclean)
	(cd AnalyzerTools; make distclean)
	(cd external/GEScaleSyst; make distclean)
	(cd Analyzers; make distclean)
	(cd Analyzers/HNL; make distclean)
	(cd Analyzers/HNLExternal; make distclean)
	(cd Analyzers/HNLOpt; make distclean)

LibTarFile = tar/lib.tar.gz
$(LibTarFile): $(wildcard ./lib/*)
	tar -czf $@ ./lib/*

DataTarFile = tar/data.tar.gz
DataFiles = $(shell find data/$(SKFlatV)/ -type f -name '*')
$(DataTarFile): $(DataFiles)
	tar --exclude=data/$(SKFlatV)/Sample -czf $@ ./data/$(SKFlatV)/

CondorTar: $(LibTarFile) $(DataTarFile)
