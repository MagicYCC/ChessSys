use chess_sys_db;

ALTER TABLE ChessRoom MODIFY charging_formula TEXT;
ALTER TABLE ChessFormulaChanges MODIFY new_formula TEXT;
ALTER TABLE ChessFormulaChanges MODIFY old_formula TEXT;
