TRANSLATIONS = $$PWD/en.ts \
               $$PWD/ru.ts

lrelease.input = TRANSLATIONS
lrelease.output = $$OUT_PWD/translations/${QMAKE_FILE_BASE}.qm
lrelease.commands = $$[QT_INSTALL_BINS]/lrelease ${QMAKE_FILE_IN} -qm ${QMAKE_FILE_OUT}
lrelease.CONFIG = no_link target_predeps
QMAKE_EXTRA_COMPILERS = lrelease

translations.files = $$OUT_PWD/translations
translations.path = $$PREFIX/share/$$TARGET
INSTALLS += translations
DEFINES += TRANSLATIONS_PATH=\\\"$$translations.path/translations\\\"