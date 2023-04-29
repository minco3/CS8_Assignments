#include "file_record.h"

long FileRecord::write(fstream &outs)
{
  // Take the Record r and write it into file f and return the record number of this Record
  // r.write(f); calls this function

  // Write to the end of the file
  outs.seekg(0, outs.end);
  // Retrieves the current position of the file pointer
  long pos = outs.tellp();
  // Insert the size of record items into file
  outs.write(_record, MAX);
  // Return the record number
  return pos / MAX;
}

long FileRecord::read(fstream &ins, long recno)
{
  // Save sixth record in file to Record r and returns the number of bytes read
  // r.read(f, 6); calls this function

  // Calculate the position of the record in the file
  long pos = recno * MAX;
  // Set the file pointer to the pos starting from the beginning of the file
  ins.seekg(pos, ios_base::beg);
  // Read the record from the file
  ins.read(_record, MAX);
  // Set the end of cstring with null
  // For example: _records[] => [zero'\0' trash ... trash]
  _record[ins.gcount()] = '\0';
  // Return the number of bytes read
  return ins.gcount();
}