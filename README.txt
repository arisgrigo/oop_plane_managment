AM: 1115201800036

Εντολές του Makefile:

make ask3
Δημιουργεί αντικειμενικά αρχεία και το εκτελέσιμο ask3

make clean
Διαγράφει αντικειμενικά αρχεία και το εκτελέσιμο ask3

Πληροφοριές και αιτιολογήσεις:

Για το compile του προγράμματος χρησιμοποιείται C++11, κυρίως για μικρά πράγματα όπως η συνάρτηση to_string και η παραγωγή random αριθμών.

Το πρόγραμμα αποτελειται απο 4 header files:
1. Basic_Objects.h στο οποίο περιέχονται οι δηλώσεις και οι ορισμοί των κλάσεων Object(abstract) και String.
2. Plane.h στο οποίο περιέχονται οι δηλώσεις και οι ορισμοί των κλάσεων PlaneComponent(abstract), PassengerCompartment, PrivateCompartment(abstract), EquipmentCompartment, CargoBay και Plane.
3. Employee.h στο οποίο περιέχονται οι δηλώσεις και οι ορισμοί των κλάσεων Employee(abstract), SecurityEmployee, MaintenanceEmployee, CleaningEmployee.
4. clone_encrypt_print.h στο οποίο περιέχεται μόνο η δήλωση της clone_encrypt_and_print.

Κάθε κλάση περιέχει ένα copy constructor το οποίο χρησιμοποιείται από τις συναρτήσεις clone().
Οι συναρτήσεις equal επιστρέφουν 1 αν όλα τα δεδομένα των αντικειμένων που συγκρίνονται είναι ίδια, και 0 αν δεν είναι.
Για τις συναρτήσεις equal δημιουργείται ο pointer ptr, που παίρνει τη διεύθηνση του αντικειμένου που δέχεται, με cast στο ανάλογο αντικείμενο που καλεί τις συναρτήσεις. Μέσω του ptr ελέγχονται οι τιμές των 2 συγκρίσημων αντικειμένων μεταξύ τους.
Οι συναρτήσεις toString σχηματίζουν το String που επιστρέφουν σταδιακά, μέσω της concat, καλώντας την toString της υπερκλάσης τους.
Οι συναρτήσεις process καλόυν τις συναρτήσεις workOn.

Object:
Στο private μέρος της κλάσης Object, εκτός από το id, υπάρχει και το static int id_count, το οποίο χρησιμοποιείται από τον constuctor έτσι ώστε κάθε αντικείμενο να έχει μοναδικό id (εκτός από τα αντικείμενα που δημιουργούνται από την συνάρτηση clone() που χρησιμοποιεί διαφορετικό constructor).
Οι συναρτήσεις clone, equal και toString είναι virtual, αφού χρησιμοποιούνται και από υποκλάσεις της Object.

String:
Για τις συναρτήσεις length, clear, concat, at, updateAt της String χρήσιμοποιούνται οι αντίστοιχες συναρτήσεις που παρέχονται από την std::string (append για την concat).


PlaneComponent:
Οι συναρτήσεις ready_check, process και clone είναι pure virtual αφού δεν έχουν νόημα για την κλάση PlaneComponent, αλλά για τις υποκλάσεις τους.

PassengerCompartment:
Το μέλος-δεδομένο innerComp είναι pointer σε PassengerCompartment, αφού δεν είναι σίγουρο οτί θα υπάρχει εσωτερικό PassengerCompartment σε ένα PassengerCompartment.
Υπάρχει ένας επιπλέον constructor, που δέχεται ως επιπλέον όρισμα έναν int (χρησιμοποιείται το 1), και μία επιπλέον συνάρτηση ready_check (overload), που χρήσιμοποιούνται για το εσωτερικό PassengerCompartment.
Ο constructor για το εσωτερικό PassengerCompartment υπάρχει ώστε να μην υπάρχει πιθανότητα ο εσωτερικός χώρος να έχει δικό του εσωτερικό χώρο, και η 2η ready_check υπάρχει ώστε να εμφανίζεται πιο ειδικό μήνυμα για το εσωτερικό PassengerCompartment.
Εκτός από τις συναρτήσεις που ζητούνται υπάρχει και η inside_exists ή οποία επιστρέφει 1 αν υπάρχει εσωτερικό PassengerCompartment (0 αλλίως) και η get_inner_id που επιστρέφει το id του εσωτερικού PassengerCompartment.

Plane:
Το μέλος-δεδομένο passengerCompartment είναι pointer σε pointer σε PassengerCompartment αφού ο αριθμός των PassengerCompartment κρίνεται στον constructor.
Για την παραγωγή τυχαίων αριθμών που χρησιμοποιείται στον constructor της Plane γίνεται χρήση της srand και rand.
Η ready_check, toString και η equal της Plane καλεί τις αντίστοιχες συναρτήσεις των αντικειμένων από τα οποία αποτελείται.
Η process της Plane καλεί τις συναρτήσεις workOn για καθε αντικείμενο από το οποίο αποτελείται.


Για την κλάση Employee και τις υποκλάσεις της, εκτός από τα μέλη-δεδομένα που ζητούνται, περιλαμβάνω και τον int hasWorked, που λαμβάνει τιμή 1, μέσω της process της Plane. (Ο Employee καλείται από την process της Plane, και αφού γίνουν όλα τα workOn στην Plane, το hasWorked γίνεται 1 μέσω της worked()).
Το hasWorked ελέγχεται από την report() ή οποία εκτυπώνει ανάλογο μήνυμα με την τιμή της hasWorked.
Κάθε υποκλάση της Employee έχει μία workOn για κάθε Compartment στο οποίο καλείται να δουλέψει, ώστε να εκτυπόνται κατάλληλα μηνύματα.

Employee:
Οι συναρτήσεις workOn, worked, report και clone είναι pure virtual αφού δεν έχουν νόημα για την κλάση Employee, αλλά για τις υποκλάσεις τους.


clone_encrypt_and_print:
Από το αρχικό String αντικαθιστόνται στο max 2/3 των χαρακτήρων (ο αριθμός επιλέγεται τυχαία), και στο ελάχιστο 4.
Κάθε χαρακτήρας (εκτός απο \t και \n) αντικαθιστάται από έναν τυχαίο χαρακτήρα που επιλέγεται με τον εξής τρόπο: new_char = 'a' + rand() % 26;