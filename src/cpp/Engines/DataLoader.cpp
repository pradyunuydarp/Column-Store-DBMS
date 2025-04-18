//
// Created by Pradyun Devarakonda on 12/03/25.
//

#include "DataLoader.h"


//bool DMLEngine::loadDatafromCSV(const & Database, const string & CSVfile, const string & RelationName){
    // Load data from CSV file into the specified relation in the specified database.
    // The CSV file should have a header row with the attribute names.
    // The order of the attributes in the CSV file should match the order of the attributes in the relation.
    // The CSV file should have one row for each tuple in the relation.
    // The CSV file should be comma-separated.
    // The CSV file should not have any quotes around the attribute values.
    // The CSV file should not have any empty lines.
    // The CSV file should not have any empty values.
    // The CSV file should not have any duplicate tuples.
    // The CSV file should not have any tuples that violate the primary key constraint.
    // The CSV file should not have any tuples that violate the foreign key constraint.
    // The CSV file should not have any tuples that violate the check constraint.
    // The CSV file should not have any tuples that violate the unique constraint.
    // The CSV file should not have any tuples that violate the not null constraint.
    // The CSV file should not have any tuples that violate the default constraint.
    // The CSV file should not have any tuples that violate the data type constraint.
    // The CSV file should not have any tuples that violate the domain constraint.
    // The CSV file should not have any tuples that violate the cardinality constraint.
    // The CSV file should not have any tuples that violate the referential integrity constraint.
    // The CSV file should not have any tuples that violate the entity integrity constraint.
    // The CSV file should not have any tuples that violate the user-defined constraint.
    // The CSV file should not have any tuples that violate the null constraint.
    // The CSV file should not have any tuples that violate the key constraint.
    // The CSV file should not have any tuples that violate the integrity constraint.
    // The CSV file should not have any tuples that violate the constraint.
    // The CSV file should not have any tuples that violate the schema constraint.
    // The CSV file should not have any tuples that violate the table constraint.
    // The CSV file should not have any tuples that violate the view constraint.
    // The CSV file should not have any tuples that violate the index constraint.
    // The CSV file should not have any tuples that violate the trigger constraint.
    // The CSV file should not have any tuples that violate the security constraint.
    // The CSV file should not have any tuples that violate the authorization constraint.
    // The CSV file should not have any tuples that violate the access constraint.

//bool DataLoader::loadDataFromCSV(Database* db, const std::string& CSVfile, const std::string& relationName) {
//    std::ifstream file(CSVfile);
//    if (!file.is_open()) {
//        std::cerr << "Error: Unable to open CSV file " << CSVfile << std::endl;
//        return false;
//    }
//
//    std::stringstream buffer;
//    buffer << file.rdbuf();
//    std::string fileContent = buffer.str();
//
//    Tbl::Table table(fileContent);
//    if (!table.isValid()) { // Ensure Table is valid
//        std::cerr << "Error: Failed to parse CSV data." << std::endl;
//        return false;
//    }
//
//    Relation* relation = db.getRelation(relationName);
//    if (!relation) {
//        std::cerr << "Error: Relation " << relationName << " not found in database." << std::endl;
//        return false;
//    }
//
//    const auto &dbName = db.getName();
//    const auto& attributes = relation->getCAttributes();
//
//    if (table.NumCols() != attributes.size()) {
//        std::cerr << "Error: CSV columns do not match the relation schema." << std::endl;
//        return false;
//    }
//
//    std::unordered_map<std::string, std::ofstream> columnFiles;
//    for (const auto& pair : attributes) {
//        auto& attr = pair.second;
//        std::string columnFilePath = "../Databases/" + dbName + "/" + relationName + "/" + attr->name + ".dat";
//
//        std::ofstream& outFile = columnFiles[attr->name];
//        outFile.open(columnFilePath, std::ios::app | std::ios::binary);
//        if (!outFile.is_open()) {
//            std::cerr << "Error: Unable to open column file " << columnFilePath << std::endl;
//
//            // Close previously opened files
//            for (auto& pair : columnFiles) {
//                if (pair.second.is_open()) pair.second.close();
//            }
//            return false;
//        }
//    }
//
//    // Iterate over each row
//    for (size_t row = 0; row < table.NumRows(); ++row) {
//        size_t colIndex = 0;  // Reset column index for each row
//
//        for (const auto& pair : attributes) {
//            const auto& attr = pair.second;
//            std::ofstream& outFile = columnFiles[attr->name];
//
//            try {
//                if (attr->type == "int") {
//                    int value = table.GetInt(row, colIndex);
//                    outFile.write(reinterpret_cast<const char*>(&value), sizeof(int));
//                } else if (attr->type == "float") {
//                    float value = static_cast<float>(table.GetDouble(row, colIndex));
//                    outFile.write(reinterpret_cast<const char*>(&value), sizeof(float));
//                } else if (attr->type == "Date_DDMMYYYY_Type") {
//                    // Date_DDMMYYYY_Type date = Date_DDMMYYYY_Type::parse(table.GetString(row, colIndex));
//                    // std::string binaryDate = date.toBinary(); // Ensure a proper serialization method
//                    // outFile.write(binaryDate.data(), binaryDate.size());
//                    Date_DDMMYYYY_Type date = Date_DDMMYYYY_Type::parse(table.GetString(row, colIndex));
//                    outFile.write(reinterpret_cast<const char*>(&date), sizeof(Date_DDMMYYYY_Type));
//                } else {
//                    std::string value = table.GetString(row, colIndex);
//                    size_t len = value.size();
//                    outFile.write(reinterpret_cast<const char*>(&len), sizeof(size_t));
//                    outFile.write(value.c_str(), len);
//                }
//            } catch (const std::exception& e) {
//                std::cerr << "Error processing column " << attr->name << " in row " << row << ": " << e.what() << std::endl;
//
//                // Cleanup before returning
//                for (auto& pair : columnFiles) {
//                    pair.second.close();
//                }
//                return false;
//            }
//
//            colIndex++;
//        }
//    }
//
//    // Close all files
//    for (auto& pair : columnFiles) {
//        pair.second.close();
//    }
//
//    return true;
//}
bool DataLoader::loadDataFromCSV(Database* db, const std::string& CSVfile, const std::string& relationName) {
    std::ifstream file(CSVfile);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open CSV file " << CSVfile << std::endl;
        return false;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    Tbl::Table table(buffer.str());
    if (!table) { // Check if table was successfully parsed
        std::cerr << "Error: Failed to parse CSV data." << std::endl;
        return false;
    }

    Relation* relation = db->getRelation(relationName);
    if (!relation) {
        std::cerr << "Error: Relation " << relationName << " not found in database." << std::endl;
        return false;
    }

    const auto& dbName = db->getName();
    const auto& attributes = relation->getCAttributes();

    if (table.GetNumColumns() != attributes.size()) {
        std::cerr << "Error: CSV columns do not match the relation schema." << std::endl;
        return false;
    }

    std::unordered_map<std::string, std::ofstream> columnFiles;
    for (const auto& pair : attributes) {
        auto& attr = pair.second;
        std::string columnFilePath = "../Databases/" + dbName + "/" + relationName + "/" + attr->name + ".dat";

        std::ofstream& outFile = columnFiles[attr->name];
        outFile.open(columnFilePath, std::ios::app | std::ios::binary);
        if (!outFile.is_open()) {
            std::cerr << "Error: Unable to open column file " << columnFilePath << std::endl;
            for (auto& pair : columnFiles) {
                if (pair.second.is_open()) pair.second.close();
            }
            return false;
        }
    }

    for (size_t row = 0; row < table.GetNumRows(); ++row) {
        size_t colIndex = 0;
        for (const auto& pair : attributes) {
            const auto& attr = pair.second;
            std::ofstream& outFile = columnFiles[attr->name];

            try {
                if (attr->type == "int") {
//                    int value = table.Get<int>(row, colIndex);
                    int64_t value = table.Get<int64_t>(row, colIndex);
                    outFile.write(reinterpret_cast<const char*>(&value), sizeof(int));
                } else if (attr->type == "float") {
                    float value = static_cast<float>(table.Get<double>(row, colIndex));
                    outFile.write(reinterpret_cast<const char*>(&value), sizeof(float));
                } else if (attr->type == "Date_DDMMYYYY_Type") {
                    std::string dateStr = table.Get<std::string>(row, colIndex);
                    Date_DDMMYYYY_Type date = Date_DDMMYYYY_Type::parse(dateStr);
                    outFile.write(reinterpret_cast<const char*>(&date), sizeof(Date_DDMMYYYY_Type));
                } else {
                    std::string value = table.Get<std::string>(row, colIndex);
                    size_t len = value.size();
                    outFile.write(reinterpret_cast<const char*>(&len), sizeof(size_t));
                    outFile.write(value.c_str(), len);
                }
            } catch (const std::exception& e) {
                std::cerr << "Error processing column " << attr->name << " in row " << row << ": " << e.what() << std::endl;
                for (auto& pair : columnFiles) {
                    pair.second.close();
                }
                return false;
            }

            colIndex++;
        }
    }

    for (auto& pair : columnFiles) {
        pair.second.close();
    }

    return true;
}
