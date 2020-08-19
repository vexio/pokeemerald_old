# JSON files are run through jsonproc, which is a tool that converts JSON data to an output file
# based on an Inja template. https://github.com/pantor/inja

AUTO_GEN_TARGETS += $(DATA_SRC_SUBDIR)/wild_encounters.h
$(DATA_SRC_SUBDIR)/wild_encounters.h: $(DATA_SRC_SUBDIR)/wild_encounters.json $(DATA_SRC_SUBDIR)/wild_encounters.json.txt
	$(JSONPROC) $^ $@

$(C_BUILDDIR)/wild_encounter.o: c_dep += $(DATA_SRC_SUBDIR)/wild_encounters.h

AUTO_GEN_TARGETS_EVENT_OBJECTS := $(DATA_SRC_SUBDIR)/object_events/object_event_pic_tables.h $(DATA_SRC_SUBDIR)/object_events/object_event_graphics_info_pointers.h $(DATA_SRC_SUBDIR)/object_events/object_event_graphics_info.h $(DATA_SRC_SUBDIR)/object_events/object_event_graphics.h include/constants/event_objects.h
AUTO_GEN_TARGETS += $(AUTO_GEN_TARGETS_EVENT_OBJECTS)

$(DATA_SRC_SUBDIR)/object_events/object_event_graphics_info_pointers.h: $(DATA_SRC_SUBDIR)/object_events/event_objects.json $(DATA_SRC_SUBDIR)/object_events/object_event_graphics_info_pointers.h.json.txt
	$(JSONPROC) $^ $@

$(DATA_SRC_SUBDIR)/object_events/object_event_graphics_info.h: $(DATA_SRC_SUBDIR)/object_events/event_objects.json $(DATA_SRC_SUBDIR)/object_events/object_event_graphics_info.h.json.txt
	$(JSONPROC) $^ $@

$(DATA_SRC_SUBDIR)/object_events/object_event_graphics.h: $(DATA_SRC_SUBDIR)/object_events/event_objects.json $(DATA_SRC_SUBDIR)/object_events/object_event_graphics.h.json.txt
	$(JSONPROC) $^ $@

$(DATA_SRC_SUBDIR)/object_events/object_event_pic_tables.h: $(DATA_SRC_SUBDIR)/object_events/event_objects.json $(DATA_SRC_SUBDIR)/object_events/object_event_pic_tables.h.json.txt
	$(JSONPROC) $^ $@

include/constants/event_objects.h: $(DATA_SRC_SUBDIR)/object_events/event_objects.json include/constants/event_objects.h.json.txt
	$(JSONPROC) $^ $@

EVENT_OBJECT_GRAPHICS := $(shell find graphics/object_events/pics -type f -name '*.png')
EVENT_OBJECT_4BPP := $(patsubst %.png, %.4bpp, $(EVENT_OBJECT_GRAPHICS))

EVENT_OBJECT_PALS := $(shell find graphics/object_events/palettes -type f -name '*.pal')
EVENT_OBJECT_EXPLICIT_GBAPALS := $(patsubst %.pal, %.gbapal, $(EVENT_OBJECT_PALS))
EVENT_OBJECT_GBAPALS := $(patsubst %.png, %.gbapal, $(EVENT_OBJECT_GRAPHICS))

$(C_BUILDDIR)/event_object_movement.o: c_dep += $(AUTO_GEN_TARGETS_EVENT_OBJECTS) $(EVENT_OBJECT_4BPP) $(EVENT_OBJECT_GBAPALS) $(EVENT_OBJECT_EXPLICIT_GBAPALS)
