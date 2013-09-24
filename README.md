SSoftwareUpdater
================

##Simple updater

###usage:
updater -platform [platform-name] -version [version-ID] -link [link-to-file]

	"platform"
		windows
		linux
		osx
		etc.. whatever yours
	
	"version"  - version  e.g. 2.4.0a
		new version must be greater than old to start updating
	
	"link"  - link with instructions file in XML or JSON(not ready)
		you can find file format below
	
	"-soft"  - download file and run setup only when next time main program started

###example
	updater -platform windows -version 032 -link http://127.0.0.1/updates.xml
	updater -platform windows -version 032 -link http://127.0.0.1/updates.xml -soft

### [XML file example (updates on server side)] (https://github.com/Esenin/SSoftwareUpdater/blob/master/updates.xml)