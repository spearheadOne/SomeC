DEMOS = base_staff/basics base_staff/bit_ops base_staff/concat_files \
        base_staff/input_counter base_staff/keywords base_staff/line_sort \
        base_staff/long_line base_staff/sort data_structures/linked_list \
        data_structures/double_linked_list data_structures/circular_list \
        data_structures/chained_hashtable data_structures/set \
        data_structures/stack data_structures/queue encryption
PYTHON ?= python3

.PHONY: all clean check check-sanitize $(DEMOS)
all: $(DEMOS)

$(DEMOS):
	$(MAKE) -C $@

clean:
	@set -e; for demo in $(DEMOS); do $(MAKE) -C $$demo clean; done

check:
	$(PYTHON) tests/smoke_test.py

check-sanitize:
	$(PYTHON) tests/smoke_test.py --sanitize
