# Essay Solutions 
######By Heather Dalton

##Milestone 1: 
No required english written part.


##Milestone 2: 
In 500 words or less, write a description of the procedure used to encrypt and transmit the file. 
Include in your description answers to at least the following questions: Did you use asymmetric 
or symmetric encryption? What are the keys for the crypto-system? <--(Kendall told me for this question it is the plainText) 
What are the algorithms used by the crypto-system? What are the strengths and weakness of your approach?

I used an encryption system that is already on most computers. When exporting a file a user has 
the option in the settings to add an encryption. They can do this by right clicking the file, selecting 
properties, advanced attributes, and encrypting the file. By encrypting, the users is just adding 
an extra layer of protection through password protection. For this part of the assignment I used 
a symmetric encryption style to encrypt a pdf file. For a secure way of transfer of the encryption 
and decryption key I slacked the key to Dr. Stanly after making sure it was secure. The password that I chose to use was 
"fryingpan2010." By exporting a file into a pdf there is an option to add a password. This is a basic 
password protection algorithm where if the recipient doesn't have the correct password, that user will be unable to open the pdf. A strength to 
this approach is that it is very easy for a common person to encrypt a pdf. On the other hand, if the password 
isn’t strong or protected an attacker would be able to get into the file pretty easily. That is 
the main weakness of a symmetric encryption. Once the attacker gets hold of the password, that is 
the only check to make sure the person trying to access it is legit or not.



##Milestone 3:
In 500 words or less, write a description of the procedure used to encrypt and send the email 
message. Include in your description answers to at least the following questions: Did you use 
asymmetric or symmetric encryption? What are the keys for the crypto-system? What are the algorithms
 used by the crypto-system? What are the strengths and weakness of your approach?

When encrypting an email message I used thunderbird. In Thunderbird when sending an email their is an option
to encrypt a message (this is under the security tab when writing an email). By requiring an encryption, the email
automatically sends your public key along with an encrypted message to the recipient. Before sending though, the 
public key of the recipient is pulled in. This method of pgp encryption is asymmetric. Both the public key of the
sender, public key of the recipient, and the privates for the sender and recipient are used. The public's are used to 
decrypt the message while the public checks the private to see if it is the right person. The algorithm that 
is used by this crypto-system is pgp. A strength of using a pgp is that it checks to make sure it is the right 
recipient before decrypting the message. A weakness of pgp is that both the sender and the recipient have to
have compatible versions of pgp.         