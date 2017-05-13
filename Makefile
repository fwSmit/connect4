.PHONY: clean All

All:
	@echo "----------Building project:[ connect4 - Debug ]----------"
	@cd "connect4" && "$(MAKE)" -f  "connect4.mk"
clean:
	@echo "----------Cleaning project:[ connect4 - Debug ]----------"
	@cd "connect4" && "$(MAKE)" -f  "connect4.mk" clean
