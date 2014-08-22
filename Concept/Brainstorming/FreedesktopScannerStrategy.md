### ===This Document Does Not Reflect The Current State Of Development===
It is only here "for the record", so others can reproduce the thoughts that led to certain decisions.

# FreedesktopScannerStrategy

This is the first concrete implementation of the `AbstractScannerStrategy` class, which is supposed to parse [index.theme](http://standards.freedesktop.org/icon-theme-spec/icon-theme-spec-latest.html) files.

A conceptual description of the parsing algorithm follows:

- Local variable: `unique_ptr<QVector<Icon>> icons`
- Local variable: `unique_ptr<IconClassification> classifications`
- Open InputStream: `index.theme`
- Skip lines until `Directories`
- Read and tokenize `Directories` String into `QStringList directories`
- Read line by line
- If starts with "`[`" and following string is contained in `directores`:
    - Scan following lines (abort at blank line) for `Type`:
        - If `Type=Scalable`:
            - AddClassificationIfNotExists: `Resolution.Scalable`
        - If `Type=Fixed` or `Type=Threshold`:
            - Scan following lines (abort at blank line) for `Size`:
                - AddClassificationIfNotExists: `Resolution.SizeValue`
    - Scan following lines (abort at blank line) for `Context`:
        - AddClassificationIfNotExists: `Context.Type`
    - Now scan all files in the described category, create an `Icon` instance for each and add the aforementioned categories to them
    - Add the new `Icon` to `icons`
- Create an `IconSet` instance by passing `icons` and `classifications`
- Return that `IconSet`
                
               
            
            