#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct TCriminal
{
  struct TCriminal  * m_Next;
  char              * m_Name;
  struct TCriminal ** m_Contacts;
  size_t              m_Cnt;
  size_t              m_Capacity;
} TCRIMINAL;

#endif /* __PROGTEST__ */

/** 
 * @brief Creates a new criminal record and adds it to the beginning of a linked list.
 *
 * @param name The name of the criminal for the new record.
 * @param next Pointer to the first element of the linked list to connect the new record to.
 *             If the list is empty, this should be NULL.
 * @return Pointer to the newly created criminal record.
 *
 */
TCRIMINAL        * createRecord ( const char      * name,
                                  TCRIMINAL       * next )
{
    TCRIMINAL *newCriminal = (TCRIMINAL *)malloc(sizeof(TCRIMINAL));
    newCriminal->m_Name = strdup(name);
    newCriminal->m_Next = next;
    newCriminal->m_Contacts = NULL;
    newCriminal->m_Cnt = 0;
    newCriminal->m_Capacity = 0;
    return newCriminal;
}

/**
 * @brief Frees the memory allocated for a linked list of criminal records.
 *
 * @param src Pointer to the first element of the linked list to be freed.
 *            If the list is empty (NULL), the function does nothing.
 */
void               freeList     ( TCRIMINAL       * src )
{
    while (src != NULL) {
        TCRIMINAL * temp = src;
        src = src->m_Next;

        free(temp->m_Name);
        free(temp->m_Contacts);
        free(temp);
    }
}

/**
 * @brief Creates a deep copy of a linked list of criminals.
 * 
 * This function copies each criminal record in the 'src' list, including their name and contacts.
 * 
 * @param src Pointer to the first element of the linked list to be copied.
 * @return Pointer to the first element of the newly created copied list, or NULL if it fails.
 */

TCRIMINAL * cloneList ( TCRIMINAL * src ) {
    if (!src) return NULL;

    TCRIMINAL * srcIter = src;
    TCRIMINAL * newHead = NULL, *newTail = NULL, *temp;

    while (srcIter != NULL) {
        temp = createRecord(srcIter->m_Name, NULL);
        if (!temp) {
            freeList(newHead); 
            return NULL;
        }

        if (newTail) {
            newTail->m_Next = temp;
        } else {
            newHead = temp;
        }
        newTail = temp;

        if (srcIter->m_Cnt > 0) {
            temp->m_Contacts = (TCRIMINAL **)malloc(srcIter->m_Cnt * sizeof(TCRIMINAL *));
            if (!temp->m_Contacts) {
                freeList(newHead); 
                return NULL;
            }
            temp->m_Capacity = srcIter->m_Cnt;
            temp->m_Cnt = srcIter->m_Cnt;
        }

        srcIter = srcIter->m_Next;
    }

    srcIter = src;
    TCRIMINAL * newIter = newHead;
    while (srcIter != NULL) {
        for (size_t i = 0; i < srcIter->m_Cnt; i++) {
            TCRIMINAL * originalContact = srcIter->m_Contacts[i];
            TCRIMINAL * newContact = newHead;

            while (newContact != NULL && originalContact != NULL) {
                if (!strcmp(newContact->m_Name, originalContact->m_Name)) {
                    newIter->m_Contacts[i] = newContact;
                    break;
                }
                newContact = newContact->m_Next;
            }
        }
        srcIter = srcIter->m_Next;
        newIter = newIter->m_Next;
    }

    return newHead;
}

/**
 * @brief Adds a contact to a criminal record's contact list.
 * 
 * @param dst The criminal record to which the contact will be added.
 * @param contact The criminal record that represents the new contact to be added.
 */
void               addContact   ( TCRIMINAL       * dst,
                                  TCRIMINAL       * contact )
{
    if (dst->m_Cnt >= dst->m_Capacity) {
        size_t newCapacity = dst->m_Capacity == 0 ? 1 : dst->m_Capacity * 2;
        TCRIMINAL ** newContacts = (TCRIMINAL **)realloc(dst->m_Contacts, newCapacity * sizeof(TCRIMINAL *));
        if (!newContacts) {
            return;
        }
        dst->m_Contacts = newContacts;
        dst->m_Capacity = newCapacity;
    }

    dst->m_Contacts[dst->m_Cnt] = contact;
    dst->m_Cnt++;
}


#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
  TCRIMINAL * a, *b;
  char tmp[100];

  assert ( sizeof ( TCRIMINAL ) == 3 * sizeof ( void * ) + 2 * sizeof ( size_t ) );
  a = nullptr;
  a = createRecord ( "Peter", a );
  a = createRecord ( "John", a );
  a = createRecord ( "Joe", a );
  a = createRecord ( "Maria", a );
  addContact ( a, a -> m_Next );
  addContact ( a -> m_Next -> m_Next, a -> m_Next -> m_Next -> m_Next );
  addContact ( a -> m_Next -> m_Next -> m_Next, a -> m_Next );
  assert ( a
           && ! strcmp ( a -> m_Name, "Maria" )
           && a -> m_Cnt == 1
           && a -> m_Contacts[0] == a -> m_Next );
  assert ( a -> m_Next
           && ! strcmp ( a -> m_Next -> m_Name, "Joe" )
           && a -> m_Next -> m_Cnt == 0 );
  assert ( a -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Name, "John" )
           && a -> m_Next -> m_Next -> m_Cnt == 1
           && a -> m_Next -> m_Next -> m_Contacts[0] == a -> m_Next -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && a -> m_Next -> m_Next -> m_Next -> m_Cnt == 1
           && a -> m_Next -> m_Next -> m_Next -> m_Contacts[0] == a -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next == nullptr );
  b = cloneList ( a );
  strcpy ( tmp, "Moe" );
  a = createRecord ( tmp, a );
  strcpy ( tmp, "Victoria" );
  a = createRecord ( tmp, a );
  strcpy ( tmp, "Peter" );
  a = createRecord ( tmp, a );
  addContact ( b -> m_Next -> m_Next -> m_Next, b -> m_Next -> m_Next );
  assert ( a
           && ! strcmp ( a -> m_Name, "Peter" )
           && a -> m_Cnt == 0 );
  assert ( a -> m_Next
           && ! strcmp ( a -> m_Next -> m_Name, "Victoria" )
           && a -> m_Next -> m_Cnt == 0 );
  assert ( a -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Name, "Moe" )
           && a -> m_Next -> m_Next -> m_Cnt == 0 );
  assert ( a -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Name, "Maria" )
           && a -> m_Next -> m_Next -> m_Next -> m_Cnt == 1
           && a -> m_Next -> m_Next -> m_Next -> m_Contacts[0] == a -> m_Next -> m_Next -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "Joe" )
           && a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Cnt == 0 );
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "John" )
           && a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Cnt == 1
           && a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Contacts[0] == a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Cnt == 1
           && a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Contacts[0] == a -> m_Next -> m_Next -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next -> m_Next == nullptr );
  assert ( b
           && ! strcmp ( b -> m_Name, "Maria" )
           && b -> m_Cnt == 1
           && b -> m_Contacts[0] == b -> m_Next );
  assert ( b -> m_Next
           && ! strcmp ( b -> m_Next -> m_Name, "Joe" )
           && b -> m_Next -> m_Cnt == 0 );
  assert ( b -> m_Next -> m_Next
           && ! strcmp ( b -> m_Next -> m_Next -> m_Name, "John" )
           && b -> m_Next -> m_Next -> m_Cnt == 1
           && b -> m_Next -> m_Next -> m_Contacts[0] == b -> m_Next -> m_Next -> m_Next );
  assert ( b -> m_Next -> m_Next -> m_Next
           && ! strcmp ( b -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && b -> m_Next -> m_Next -> m_Next -> m_Cnt == 2
           && b -> m_Next -> m_Next -> m_Next -> m_Contacts[0] == b -> m_Next
           && b -> m_Next -> m_Next -> m_Next -> m_Contacts[1] == b -> m_Next -> m_Next );
  assert ( b -> m_Next -> m_Next -> m_Next -> m_Next == nullptr );
  freeList ( a );
  addContact ( b -> m_Next, b -> m_Next );
  a = cloneList ( b );
  assert ( a
           && ! strcmp ( a -> m_Name, "Maria" )
           && a -> m_Cnt == 1
           && a -> m_Contacts[0] == a -> m_Next );
  assert ( a -> m_Next
           && ! strcmp ( a -> m_Next -> m_Name, "Joe" )
           && a -> m_Next -> m_Cnt == 1
           && a -> m_Next -> m_Contacts[0] == a -> m_Next );
  assert ( a -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Name, "John" )
           && a -> m_Next -> m_Next -> m_Cnt == 1
           && a -> m_Next -> m_Next -> m_Contacts[0] == a -> m_Next -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next
           && ! strcmp ( a -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && a -> m_Next -> m_Next -> m_Next -> m_Cnt == 2
           && a -> m_Next -> m_Next -> m_Next -> m_Contacts[0] == a -> m_Next
           && a -> m_Next -> m_Next -> m_Next -> m_Contacts[1] == a -> m_Next -> m_Next );
  assert ( a -> m_Next -> m_Next -> m_Next -> m_Next == nullptr );
  assert ( b
           && ! strcmp ( b -> m_Name, "Maria" )
           && b -> m_Cnt == 1
           && b -> m_Contacts[0] == b -> m_Next );
  assert ( b -> m_Next
           && ! strcmp ( b -> m_Next -> m_Name, "Joe" )
           && b -> m_Next -> m_Cnt == 1
           && b -> m_Next -> m_Contacts[0] == b -> m_Next );
  assert ( b -> m_Next -> m_Next
           && ! strcmp ( b -> m_Next -> m_Next -> m_Name, "John" )
           && b -> m_Next -> m_Next -> m_Cnt == 1
           && b -> m_Next -> m_Next -> m_Contacts[0] == b -> m_Next -> m_Next -> m_Next );
  assert ( b -> m_Next -> m_Next -> m_Next
           && ! strcmp ( b -> m_Next -> m_Next -> m_Next -> m_Name, "Peter" )
           && b -> m_Next -> m_Next -> m_Next -> m_Cnt == 2
           && b -> m_Next -> m_Next -> m_Next -> m_Contacts[0] == b -> m_Next
           && b -> m_Next -> m_Next -> m_Next -> m_Contacts[1] == b -> m_Next -> m_Next );
  assert ( b -> m_Next -> m_Next -> m_Next -> m_Next == nullptr );
  freeList ( b );
  freeList ( a );
  return EXIT_SUCCESS;
}
#endif /* __PROGTEST__ */
